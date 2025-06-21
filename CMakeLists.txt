cmake_minimum_required(VERSION 3.30)

project(TamarVision VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(TamarVision.h.in ${CMAKE_BINARY_DIR}/TamarVision.h)

find_package(OpenCV 4.12.0 REQUIRED)
find_package(Eigen3 REQUIRED)

option(WITH_DLL_MD "For working with dynamic libraries and /MD" OFF)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBS})

if(WITH_DLL_MD)
	if (MSVC)
		file(GLOB OPENCV_DLLS "${OpenCV_DIR}/X64/vc17/bin/*.dll")
		add_custom_command(TARGET ${PROJECT_NAME}
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${OPENCV_DLLS}
                     $<TARGET_FILE_DIR:${PROJECT_NAME}>)
	endif (MSVC)
endif()


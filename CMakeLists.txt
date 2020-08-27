cmake_minimum_required(VERSION 3.8)
project(DuktapeTest)

set(CMAKE_CXX_STANDARD 11)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

set(DUKTAPE_TARGET Duktape)
set(DUKTAPE_SOURCES 3rd/Duktape/duktape.c)
add_library(${DUKTAPE_TARGET} ${DUKTAPE_SOURCES})

set(APP_TARGET DuktapeTest)
set(APP_SOURCES src/native/Main.cpp)
add_executable(${APP_TARGET} ${APP_SOURCES})
target_include_directories(${APP_TARGET} PUBLIC 3rd/Duktape)
target_link_libraries(${APP_TARGET} ${DUKTAPE_TARGET})

add_custom_command(
        TARGET ${APP_TARGET} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/dist $<TARGET_FILE_DIR:${APP_TARGET}>/dist
)

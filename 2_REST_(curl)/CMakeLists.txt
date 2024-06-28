cmake_minimum_required(VERSION 3.26)
project(prg_9laba_REST__curl_
        VERSION 1.0
        DESCRIPTION ""
        LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 23)
include(FetchContent)
FetchContent_Declare(
        curl
        GIT_REPOSITORY https://github.com/curl/curl.git
        GIT_TAG curl-8_7_1
)

FetchContent_MakeAvailable(curl)

add_executable(prg_9laba_REST__curl_
        main.cpp
        functions.h
        realization_fun.cpp)

target_link_libraries(prg_9laba_REST__curl_ libcurl)
cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules;${CMAKE_MODULE_PATH}")
include(cmake-modules/DownloadProject.cmake)

project(libcurl-httpbin-testsuite CXX)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic -O3 -g")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lstdc++ -lpthread -ldl")

download_project(PROJ                curl
        GIT_REPOSITORY      https://github.com/xquery/curl.git
        GIT_TAG             curlopt_curlu8
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
        )
download_project(PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
        )
download_project(PROJ                rapidjson
        GIT_REPOSITORY      https://github.com/miloyip/rapidjson.git
        GIT_TAG             master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
        )
download_project(PROJ                pugixml
        GIT_REPOSITORY      https://github.com/zeux/pugixml.git
        GIT_TAG             master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
        )

include_directories(${rapidjson_SOURCE_DIR}/include)
include_directories(${curl_SOURCE_DIR}/include)
include_directories(${pugixml_SOURCE_DIR}/src)

add_subdirectory(${pugixml_SOURCE_DIR})
add_subdirectory(${curl_SOURCE_DIR})

include(CTest)
enable_testing()
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
add_subdirectory(test)

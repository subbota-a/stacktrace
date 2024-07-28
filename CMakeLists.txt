cmake_minimum_required(VERSION 3.20)

# vcpkg configuration
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -fPIC -stdlib=libc++" CACHE STRING "")
set(CMAKE_EXE_LINKER_FLAGS_INIT "${CMAKE_EXE_LINKER_FLAGS_INIT} -fuse-ld=lld" CACHE STRING "")

# triplet is only needed to compile new binaries with stdlib=libc++
set(VCPKG_TARGET_TRIPLET x64-linux-clang CACHE STRING "Vcpkg target triplet")
set(VCPKG_HOST_TRIPLET x64-linux-clang CACHE STRING "Vcpkg host triplet")

# Project name
project(stacktrace-test)

# because cmake_policy might be unset later
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
cmake_policy(SET CMP0077 NEW)
cmake_policy(SET CMP0067 NEW)

find_package(Boost REQUIRED)

add_subdirectory(stacktrace)

add_executable(ver1
    main.cpp 
)
target_link_libraries(ver1 PRIVATE stacktrace)


add_executable(ver2
    main.cpp 
    stacktrace/backtrace.cpp
    stacktrace/from_exception.cpp
)
target_link_libraries(ver2 PRIVATE stacktrace)
target_include_directories(ver2 PRIVATE stacktrace/include)

find_package(Boost REQUIRED)

add_library(stacktrace STATIC
    backtrace.cpp
    from_exception.cpp
)
target_link_libraries(stacktrace PRIVATE backtrace dl PUBLIC Boost::headers)
target_include_directories(stacktrace PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

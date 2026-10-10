cmake_minimum_required(VERSION 3.25)

project(CodingTestLab VERSION 0.1.0 LANGUAGES CXX)

# 문제 파일 1개 = 실행 파일 1개. 파일마다 main()이 있어도 충돌하지 않는다.
# 타깃 이름은 problem_N (CMake 식별자 제약 회피), 실행 파일 이름은 소스 파일 스템.
file(GLOB PROBLEM_SOURCES CONFIGURE_DEPENDS "코딩테스트/*.cpp")
list(SORT PROBLEM_SOURCES)

set(problem_index 0)
foreach(problem_source IN LISTS PROBLEM_SOURCES)
    get_filename_component(problem_stem "${problem_source}" NAME_WE)
    set(problem_target "problem_${problem_index}")

    # This problem keeps editing and debugger entry points in separate projects.
    if(problem_stem STREQUAL "같은숫자는싫어")
        add_executable(${problem_target} "디버깅/Debugging/SameNumberDebug.cpp")
    else()
        add_executable(${problem_target} "${problem_source}")
    endif()
    set_target_properties(${problem_target} PROPERTIES
        OUTPUT_NAME "${problem_stem}"
        CXX_EXTENSIONS OFF
    )
    target_compile_features(${problem_target} PRIVATE cxx_std_17)

    if(MSVC)
        target_compile_options(${problem_target} PRIVATE /W4 /utf-8 /permissive-)
    else()
        target_compile_options(${problem_target} PRIVATE -Wall -Wextra -Wpedantic)
    endif()

    math(EXPR problem_index "${problem_index} + 1")
endforeach()

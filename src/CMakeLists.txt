# Zero-Clause BSD
#
# Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby
# granted.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
# INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
# AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.

cmake_minimum_required(VERSION 3.9)


add_library(conandemo-lib ConanDemo.cpp)
target_include_directories(conandemo-lib PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
    $<INSTALL_INTERFACE:include>
)
target_link_libraries(conandemo-lib
    PRIVATE
        spdlog::spdlog
)

set_target_properties(conandemo-lib PROPERTIES OUTPUT_NAME conandemo)
install(TARGETS conandemo-lib EXPORT ${PROJECT_NAME}Config DESTINATION lib)

add_library(conandemo-cli-lib STATIC ConanDemo-cli.cpp)
target_include_directories(conandemo-cli-lib INTERFACE "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(conandemo-cli-lib
    PUBLIC
        conandemo-lib
    PRIVATE
        spdlog::spdlog
)

add_executable(conandemo main.cpp)
target_link_libraries(conandemo conandemo-cli-lib)
install(TARGETS conandemo DESTINATION bin)

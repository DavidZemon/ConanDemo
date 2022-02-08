/**
 * @file JumpstartedSkeletonSimplified-cli.cpp
 *
 * Zero-Clause BSD
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby
 * granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#include <Zemon/JumpstartedSkeletonSimplified.h>
#include <spdlog/spdlog.h>
#include <iostream>

// Testable logic for the executable goes here
int run () {
    const Zemon::JumpstartedSkeletonSimplified instance;
    const auto result = instance.add(1, 2);
    spdlog::info("{} + {} = {}", 1, 2, result);
    return 0;
}

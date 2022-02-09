/**
 * @file ConanDemoTest.cpp
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

#include <Zemon/ConanDemo.h>

#include <spdlog/spdlog.h>
#include <gmock/gmock.h>

class ConanDemoTest : public ::testing::Test
{
    public:
        // TODO: Replace this constructor with any setup functionality you need
        ConanDemoTest() {
            spdlog::set_level(spdlog::level::err);
        }

        // TODO: Replace this destructor with any teardown functionality you need
        ~ConanDemoTest() override = default;

    protected:
        Zemon::ConanDemo testable;
};

// NOLINTNEXTLINE
TEST_F (ConanDemoTest, can_add) {
    ASSERT_EQ(3, testable.add(1, 2));
}

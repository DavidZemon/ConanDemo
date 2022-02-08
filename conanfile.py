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

import os
import shutil

from conans import ConanFile, CMake, tools


class JumpstartedSkeletonSimplified(ConanFile):
    name = 'jumpstartedskeletonsimplified'
    version = tools.load("version.txt").strip() + '-1'
    license = 'Proprietary'
    description = 'A simplified version of JumpstartedSkeleton with options chosen based on Conan demo-ability.'
    homepage = 'https://github.com/DavidZemon/JumpstartedSkeletonSimplified'
    url = 'https://github.com/DavidZemon/JumpstartedSkeletonSimplified'
    topics = 'tag1', 'tag2'
    settings = 'os', 'compiler', 'build_type', 'arch'
    options = {'shared': [True, False], 'fPIC': [True, False]}
    default_options = {'shared': False, 'fPIC': True}
    generators = 'cmake_find_package'

    build_requires = (
        'gtest/cci.20210126',
        'doxygen/[^1.8.8]'
    )
    requires = (
        'spdlog/[^1.9.2]'
    )

    exports = 'version.txt'
    scm = {
        'type': 'git',
        'url': 'auto',
        'revision': 'auto'
    }

    def build(self):
        cmake = self.cmake
        cmake.configure()
        cmake.build()
        cmake.test()

    def package(self):
        self.cmake.install()
        cmake_config_dir = os.path.join(self.package_folder, 'lib', 'cmake')
        if os.path.exists(cmake_config_dir):
            shutil.rmtree(cmake_config_dir)

        os.makedirs(os.path.join(f'{self.package_folder}', 'licenses'), exist_ok=True)
        shutil.copy2(os.path.join(self.source_folder, 'LICENSE'),
                     os.path.join(f'{self.package_folder}', 'licenses', self.name))

    def package_info(self):
        self.cpp_info.set_property('cmake_file_name', 'JumpstartedSkeletonSimplified')
        self.cpp_info.set_property('cmake_target_name', 'JumpstartedSkeletonSimplified')
        self.cpp_info.components['jumpstartedskeletonsimplified-lib'].libs = ['jumpstartedskeletonsimplified']

    @property
    def cmake(self):
        return CMake(self)

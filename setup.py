import platform

from setuptools import Extension, setup


def get_ext_modules() -> list:
    """
    获取三方模块

    Linux需要编译封装接口
    Windows直接使用预编译的pyd即可
    Mac由于缺乏二进制库支持无法使用
    """
    if platform.system() != "Linux":
        return []

    compiler_flags = [
        "-std=c++17",
        "-O3",
        "-Wno-delete-incomplete", "-Wno-sign-compare",
    ]
    extra_link_args = ["-lstdc++"]
    runtime_library_dirs = ["$ORIGIN"]

    vnxtpmd = Extension(
        "vnpy_xtp.api.vnxtpmd",
        [
            "vnpy_xtp/api/vnxtp/vnxtpmd/vnxtpmd.cpp",
        ],
        include_dirs=["vnpy_xtp/api/include",
                      "vnpy_xtp/api/vnxtp"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_xtp/api/libs", "vnpy_xtp/api"],
        libraries=["xtpquoteapi", "xtptraderapi"],
        extra_compile_args=compiler_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    vnxtptd = Extension(
        "vnpy_xtp.api.vnxtptd",
        [
            "vnpy_xtp/api/vnxtp/vnxtptd/vnxtptd.cpp",
        ],
        include_dirs=["vnpy_xtp/api/include",
                      "vnpy_xtp/api/vnxtp"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_xtp/api/libs", "vnpy_xtp/api"],
        libraries=["xtpquoteapi", "xtptraderapi"],
        extra_compile_args=compiler_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    return [vnxtptd, vnxtpmd]


setup(
    ext_modules=get_ext_modules(),
)

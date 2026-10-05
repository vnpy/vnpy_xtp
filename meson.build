project(
  'vnpy_xtp',
  'cpp',
  version: '2.2.32.2.4',
  license: 'MIT',
  meson_version: '>=1.7.0',
  default_options: [
    'buildtype=release',
    'cpp_std=c++17',
    'warning_level=2',
  ],
)

# 导入文件系统和Python模块
fs = import('fs')
py = import('python').find_installation(pure: false)
py_dep = py.dependency()

# 获取pybind11路径
python_cmd = host_machine.system() == 'windows' ? 'python' : 'python3'
pybind11_include_dir = run_command(python_cmd, '-c', 'import pybind11; print(pybind11.get_include())', check: true).stdout().strip()
message('使用pybind11路径: ' + pybind11_include_dir)

# 获取编译器信息
cpp = meson.get_compiler('cpp')
compiler_id = cpp.get_id()

# 输出构建目标系统信息
message('构建目标系统: ' + host_machine.system())

# 初始化变量
thostmduserapi_lib = []
thosttraderapi_lib = []
extra_cpp_args = []
extra_link_args = []

# 设置Windows特定编译选项
if host_machine.system() == 'windows'
  # Windows编译器设置
  add_project_arguments('/MT', language : 'cpp')
  
  # 设置库目录
  lib_dir = meson.current_source_dir() / 'vnpy_xtp/api/libs'
  api_dir = meson.current_source_dir() / 'vnpy_xtp/api'
  
  # 设置include目录
  include_dirs = include_directories(
    'vnpy_xtp/api/include',
    'vnpy_xtp/api/vnxtp',
    pybind11_include_dir,
  )
  
  # 定义CTP库
  thostmduserapi_lib = cpp.find_library('xtpquoteapi', 
                                       dirs: [lib_dir, api_dir],
                                       required: true)
  thosttraderapi_lib = cpp.find_library('xtptraderapi', 
                                       dirs: [lib_dir, api_dir],
                                       required: true)

# 设置Linux特定编译选项
else  # Linux
  # Linux编译器设置
  extra_cpp_args = [
    '-std=c++17',
    '-O3',
    '-Wno-delete-incomplete',
    '-Wno-sign-compare',
  ]
  
  extra_link_args = [
    '-lstdc++',
    '-Wl,-rpath,$ORIGIN',  # 添加rpath设置，使库能在运行时找到同目录下的动态库
  ]
  
  # 设置库目录
  lib_dir = meson.current_source_dir() / 'vnpy_xtp/api'
  
  # 设置include目录
  include_dirs = include_directories(
    'vnpy_xtp/api/include',
    'vnpy_xtp/api/vnxtp',
    pybind11_include_dir,
  )
  
  # 定义CTP库
  thostmduserapi_lib = cpp.find_library('xtpquoteapi', 
                                       dirs: [lib_dir],
                                       required: true)
  thosttraderapi_lib = cpp.find_library('xtptraderapi', 
                                       dirs: [lib_dir],
                                       required: true)
endif

# 创建MD模块扩展
md_module = py.extension_module(
  'vnxtpmd',
  sources: ['vnpy_xtp/api/vnxtp/vnxtpmd/vnxtpmd.cpp'],
  include_directories: include_dirs,
  dependencies: [py_dep, thostmduserapi_lib],
  cpp_args: extra_cpp_args,
  link_args: extra_link_args,
  install: true,
  subdir: 'vnpy_xtp/api'
)

# 创建TD模块扩展
td_module = py.extension_module(
  'vnxtptd',
  sources: ['vnpy_xtp/api/vnxtp/vnxtptd/vnxtptd.cpp'],
  include_directories: include_dirs,
  dependencies: [py_dep, thosttraderapi_lib],
  cpp_args: extra_cpp_args,
  link_args: extra_link_args,
  install: true,
  subdir: 'vnpy_xtp/api'
)

# 安装Python源代码
python_files = [
  ['vnpy_xtp/__init__.py', 'vnpy_xtp'],
  ['vnpy_xtp/api/__init__.py', 'vnpy_xtp/api'],
  ['vnpy_xtp/api/xtp_constant.py', 'vnpy_xtp/api'],
  ['vnpy_xtp/gateway/__init__.py', 'vnpy_xtp/gateway'],
  ['vnpy_xtp/gateway/xtp_gateway.py', 'vnpy_xtp/gateway'],
]

foreach file : python_files
  py.install_sources(
    [file[0]],
    pure: false,
    subdir: file[1]
  )
endforeach

# 安装API动态库文件
if host_machine.system() == 'windows'
  api_libs = [
    'vnpy_xtp/api/xtpquoteapi.dll',
    'vnpy_xtp/api/xtptraderapi.dll',
  ]
  
  install_data(
    api_libs,
    install_dir: py.get_install_dir() / 'vnpy_xtp/api'
  )
else  # Linux
  api_libs = [
    'vnpy_xtp/api/libxtpquoteapi.so',
    'vnpy_xtp/api/libxtptraderapi.so',
  ]
  
  install_data(
    api_libs,
    install_dir: py.get_install_dir() / 'vnpy_xtp/api'
  )
endif

# 可编辑安装的扩展在构建目录，厂商库仍在源码树。
# 拷到扩展旁边后，Windows 在 .pyd 所在目录找 DLL，Linux 用扩展的 $ORIGIN 找 .so。
# 这些拷贝不安装；正式安装仍由上面的 install_data 放到 site-packages。
foreach lib : api_libs
  fs.copyfile(lib)
endforeach
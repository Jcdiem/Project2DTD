project('P2D', 'cpp', default_options:['cpp_std=gnu++2a'])

sources = ['src/utils/Json.cpp',
           'src/utils/Flagger.cpp',
           'src/utils/draw/Atlas.cpp',
           'src/utils/draw/AtlasIndex.cpp',
           'src/utils/draw/Sprite.cpp',
           'src/Engine.cpp',
           'src/Main.cpp']

dependencies = []
link_args = []

xorg = dependency('x11', required: false)
if xorg.found()
    dependencies += xorg
    add_project_arguments('-DX11', language : 'cpp')
endif

#Standard Deps
sfml = dependency('sfml-all')
dependencies += sfml
lua = dependency('luajit') #<----
dependencies += lua
#Replace 'lua' with whatever flavor you prefer, IE: luajit, lua, lua53, lua52, lua51 and so on,
#As long as sol2 supports it, it should work here.

#Meson Built-ins
thread = dependency('threads')
dependencies += thread

#Submodules
nlohmann_json = include_directories('libs/json/include')
json = declare_dependency(include_directories: nlohmann_json)
dependencies += json

phd_sol2 = include_directories('libs/sol2/include')
sol2 = declare_dependency(include_directories: phd_sol2)
dependencies += sol2

executable(
	'P2D',
	sources: sources,
	dependencies: dependencies,
	link_args: link_args
)

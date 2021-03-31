project('P2D', 'cpp')

#cppc = meson.get_compiler('cpp')

#Standard Deps
sdl2_core = dependency('SDL2')
sdl2_image = dependency('SDL2_image')
acodec = dependency('allegro_acodec-5')
audio = dependency('allegro_audio-5')
lua = dependency('luajit')
#Replace 'lua' with whatever flavor you prefer, IE: luajit, lua, lua53, lua52, lua51 and so on,
#As long as sol2 supports it, it should work here.

#Meson Built-ins
thread = dependency('threads')

#math = cppc.find_library('m', required : false)
#dlopen = cppc.find_library('dl', required : false)

#Submodules
nlohmann_json = include_directories('libs/json/include')
json = declare_dependency(include_directories: nlohmann_json)

phd_sol2 = include_directories('libs/sol2/include')
sol2 = declare_dependency(include_directories: phd_sol2)

executable(
	'P2D',
	sources:[
	    'src/ECS/LuaEngine.cpp',
	    'src/ECS/InputManager.cpp',
	    'src/ECS/EntityWrapper.cpp',
		'src/ObjectBuilder.cpp',
		'src/TextureHandler.cpp',
		'src/AudioHandler.cpp',
		'src/Canvas_LayerData.cpp',
		'src/Canvas.cpp',
		'src/Engine.cpp',
		'src/Main.cpp'
	],
	dependencies:[
		sdl2_core,
		sdl2_image,
		json,
		lua,
		sol2,
		thread,
		audio,
		acodec
	],
	link_args:[
	]
)
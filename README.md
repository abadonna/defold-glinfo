# defold-glinfo
[Defold](https://www.defold.com) native extension for getting some OpenGL params.

## Installation
Add this project as a [Defold library dependency](http://www.defold.com/manuals/libraries/).
Open your game.project file and in the dependencies field under project add:
https://github.com/abadonna/defold-glinfo/archive/master.zip

## Usage

### glinfo.version()
Returns an opengl version or release number

### glinfo.extension(name)
Checks if an opengl extension with particular name is supported

### glinfo.texture_size()
Returns maximum supported texture size

#define EXTENSION_NAME glinfo
#define LIB_NAME "glinfo"
#define MODULE_NAME "glinfo"
#define DLIB_LOG_DOMAIN LIB_NAME

#include <dmsdk/sdk.h>
#include <gl.h>

static int Version(lua_State* L)
{
    char* str = (char*)glGetString(GL_VERSION);
    lua_pushstring(L, str);
    return 1;
}

static int Extension(lua_State* L)
{
    const char* name = luaL_checkstring(L, 1);
    char* extensions = (char*)glGetString(GL_EXTENSIONS);
    char* res = strstr (extensions, name);
    lua_pushboolean(L, res ? true : false);
    return 1;
}

static int TextureSize(lua_State* L)
{
    int nTexSize = 0;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &nTexSize);
    lua_pushnumber(L, nTexSize);

    return 1;
}

// Functions exposed to Lua
static const luaL_reg Module_methods[] =
{
    {"texture_size", TextureSize},
    {"version", Version},
    {"extension", Extension},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);

    // Register lua names
    luaL_register(L, MODULE_NAME, Module_methods);

    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result InitializeGlInfo(dmExtension::Params* params)
{
    // Init Lua
    LuaInit(params->m_L);
    printf("Registered %s Extension\n", MODULE_NAME);
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeGlInfo(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, 0, 0, InitializeGlInfo, 0, 0, FinalizeGlInfo)

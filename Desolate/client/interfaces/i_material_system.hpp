#pragma once
#include "../../sdk/structs/materials.hpp"
#include "../utilities/xor.h"
#define DECLARE_POINTER_HANDLE(name) struct name##__ { int unused; }; typedef struct name##__ *name
#define MAXSTUDIOSKINS		32

// These are given to FindMaterial to reference the texture groups that Show up on the
#define TEXTURE_GROUP_LIGHTMAP				"Lightmaps"
#define TEXTURE_GROUP_WORLD				"World textures"
#define TEXTURE_GROUP_MODEL				"Model textures"
#define TEXTURE_GROUP_VGUI				"VGUI textures"
#define TEXTURE_GROUP_PARTICLE				"Particle textures"
#define TEXTURE_GROUP_DECAL				"Decal textures"
#define TEXTURE_GROUP_SKYBOX				"SkyBox textures"
#define TEXTURE_GROUP_CLIENT_EFFECTS			"ClientEffect textures"
#define TEXTURE_GROUP_OTHER				"Other textures"
#define TEXTURE_GROUP_PRECACHED				"Precached"
#define TEXTURE_GROUP_CUBE_MAP				"CubeMap textures"
#define TEXTURE_GROUP_RENDER_TARGET			"RenderTargets"
#define TEXTURE_GROUP_UNACCOUNTED			"Unaccounted textures"
//#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER		"Static Vertex"
#define TEXTURE_GROUP_STATIC_INDEX_BUFFER		"Static Indices"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_DISP		"Displacement Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_COLOR	"Lighting Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_WORLD	"World Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_MODELS	"Model Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_OTHER	"Other Verts"
#define TEXTURE_GROUP_DYNAMIC_INDEX_BUFFER		"Dynamic Indices"
#define TEXTURE_GROUP_DYNAMIC_VERTEX_BUFFER		"Dynamic Verts"
#define TEXTURE_GROUP_DEPTH_BUFFER			"DepthBuffer"
#define TEXTURE_GROUP_VIEW_MODEL			"ViewModel"
#define TEXTURE_GROUP_PIXEL_SHADERS			"Pixel Shaders"
#define TEXTURE_GROUP_VERTEX_SHADERS			"Vertex Shaders"
#define TEXTURE_GROUP_RENDER_TARGET_SURFACE		"RenderTarget Surfaces"
#define TEXTURE_GROUP_MORPH_TARGETS			"Morph Targets"

class	i_ms_mat;
class	i_ms_mesh;
class	i_ms_vertex_buffer;
class	i_ms_index_buffer;
struct	i_ms_system_config_t;
class	i_ms_v_matrix;
class	i_ms_texture;
struct	i_ms_hwid_t;
class	i_ms_key_values;
class	i_ms_shader;
class	i_ms_vtx_texture;
class	i_ms_morph;
class	i_mat_render_ctx;
class	i_ms_call_queue;
struct	i_ms_morph_weight_t;
class	i_ms_file_list;
struct	i_ms_vtx_stream_spec_t;
struct	i_ms_shader_stencil_state_t;
struct	i_ms_mesh_instance_data_t;
class	i_ms_client_mat_sys;
class	i_ms_paint_mat;
class	i_ms_paint_map_data_mgr;
class	i_ms_paint_map_texture_mgr;
class	i_ms_gpu_mem_stats;
struct	i_ms_aspect_ratio_info_t;
struct	i_ms_cascaded_shadow_mapping_state_t;

class	i_ms_proxy_factory;
class	i_ms_texture;
class	i_ms_sys_hardware_cfg;
class	i_ms_shadow_mgr;

enum i_ms_compiled_vtf_flags {
	TEXTURE_FLAGS_POINT_SAMPLE = 1 << 0,
	TEXTURE_FLAGS_TRILINEAR = 1 << 1,
	TEXTURE_FLAGS_CLAMPS = 1 << 2,
	TEXTURE_FLAGS_CLAMPT = 1 << 3,
	TEXTURE_FLAGS_ANISOTROPIC = 1 << 4,
	TEXTURE_FLAGS_HINT_DXT5 = 1 << 5,
	TEXTURE_FLAGS_PWL_CORRECTED = 1 << 6,
	TEXTURE_FLAGS_NORMAL = 1 << 7,
	TEXTURE_FLAGS_NO_MIP = 1 << 8,
	TEXTURE_FLAGS_NO_LOD = 1 << 9,
	TEXTURE_FLAGS_ALL_MIPS = 1 << 10,
	TEXTURE_FLAGS_PROCEDURAL = 1 << 11,
	TEXTURE_FLAGS_ONE_BIT_ALPHA = 1 << 12,
	TEXTURE_FLAGS_EIGHT_BIT_ALPHA = 1 << 13,
	TEXTURE_FLAGS_ENVMAP = 1 << 14,
	TEXTURE_FLAGS_RENDER_TARGET = 1 << 15,
	TEXTURE_FLAGS_DEPTH_RENDER_TARGET = 1 << 16,
	TEXTURE_FLAGS_NO_DEBUG_OVERRIDE = 1 << 17,
	TEXTURE_FLAGS_SINGLE_COPY = 1 << 18,
	TEXTURE_FLAGS_PRE_SRGB = 1 << 19,
	TEXTURE_FLAGS_UNUSED_0x001 = 1 << 20,
	TEXTURE_FLAGS_UNUSED_0x002 = 1 << 21,
	TEXTURE_FLAGS_UNUSED_0x004 = 1 << 22,
	TEXTURE_FLAGS_NO_DEPTH_BUFFER = 1 << 23,
	TEXTURE_FLAGS_UNUSED_0x01 = 1 << 24,
	TEXTURE_FLAGS_CLAMPU = 1 << 25,
	TEXTURE_FLAGS_VERTEX_TEXTURE = 1 << 26,
	TEXTURE_FLAGS_SSBUMP = 1 << 27,
	TEXTURE_FLAGS_UNUSED_0x1 = 1 << 28,
	TEXTURE_FLAGS_BORDER = 1 << 29,
	TEXTURE_FLAGS_UNUSED_0x4 = 1 << 30,
	TEXTURE_FLAGS_UNUSED_0x8 = 1 << 31
};

enum i_ms_standard_lightmap_t {
	MATERIAL_SYSTEM_LIGHTMAP_PAGE_WHITE = -1,
	MATERIAL_SYSTEM_LIGHTMAP_PAGE_WHITE_BUMP = -2,
	MATERIAL_SYSTEM_LIGHTMAP_PAGE_pUser_DEFINED = -3
};

struct i_ms_sort_info_t {
	i_ms_mat	*material;
	int		lightmap_page_id;
};

enum i_matsys_material_thread_mode_t {
	MATERIAL_SINGLE_THREADED,
	MATERIAL_QUEUED_SINGLE_THREADED,
	MATERIAL_QUEUED_THREADED
};

enum i_ms_material_ctx_type_t {
	MATERIAL_HARDWARE_CONTEXT,
	MATERIAL_QUEUED_CONTEXT,
	MATERIAL_NULL_CONTEXT
};

enum {
	MATERIAL_ADAPTER_NAME_LENGTH = 1 << 9
};

struct i_ms_material_texture_info_t {
	int exclude_information;
};

struct i_ms_app_perf_counters_info_t {
	float ms_main;
	float ms_mst;
	float ms_gpu;
	float ms_flip;
	float ms_total;
};

struct i_ms_app_instant_counters_info_t {
	uint32_t cpu_activity_mask;
	uint32_t deferred_words_allocated;
};

struct i_matsys_material_adapter_info_t {
	char		driver_name[ MATERIAL_ADAPTER_NAME_LENGTH ];
	unsigned int	vendor_id;
	unsigned int	device_id;
	unsigned int	sub_sys_id;
	unsigned int	revision;
	int		dx_support_level;
	int		min_dx_support_level;
	int		max_dx_support_level;
	unsigned int	driver_version_high;
	unsigned int	driver_version_low;
};

struct i_ms_mat_video_mode_t {
	int		width;
	int		height;
	image_format 	format;
	int		refresh_rate;
};

enum i_ms_hdr_type_t {
	HDR_TYPE_NONE,
	HDR_TYPE_INTEGER,
	HDR_TYPE_FLOAT,
};

enum i_ms_res_change_flags_t {
	MATERIAL_RESTORE_VERTEX_FORMAT_CHANGED = 1,
	MATERIAL_RESTORE_RELEASE_MANAGED_RESOURCES
};

enum i_ms_render_target_size_mode_t {
	RT_SIZE_NO_CHANGE,
	RT_SIZE_DEFAULT,
	RT_SIZE_PICMIP,
	RT_SIZE_HDR,
	RT_SIZE_FULL_FRAME_BUFFER,
	RT_SIZE_OFFSCREEN,
	RT_SIZE_FULL_FRAME_BUFFER_ROUNDED_UP
};

enum i_ms_mat_render_target_depth_t {
	MATERIAL_RT_DEPTH_SHARED,
	MATERIAL_RT_DEPTH_SEPARATE,
	MATERIAL_RT_DEPTH_NONE,
	MATERIAL_RT_DEPTH_ONLY
};

typedef void( *mat_buffer_release_func_t )( int flags );
typedef void( *mat_buffer_restore_func_t )( int flags );
typedef void( *mode_change_callback_function_t )( void );
typedef void( *end_frame_cleanup_function_t )( void );
typedef bool( *end_frame_prior_to_next_ctx_function_t )( void );
typedef void( *on_level_shutdown_function_t )( void *data );

typedef unsigned short mat_handle_t;
DECLARE_POINTER_HANDLE( mat_lock_t );

using KeyValuesSystemFn = void* (__cdecl*)();
using GetSymbolProcFn = bool(__cdecl*)(const char*);

class CKeyValues
{
public:
	template <typename T, typename ... args_t>
	static inline constexpr T CallVFunc(void* thisptr, std::size_t nIndex, args_t... argList)
	{
		using VirtualFn = T(__thiscall*)(void*, decltype(argList)...);
		return (*(VirtualFn**)thisptr)[nIndex](thisptr, argList...);
	}

	enum EKeyTypes : int
	{
		TYPE_NONE = 0,
		TYPE_STRING,
		TYPE_INT,
		TYPE_FLOAT,
		TYPE_PTR,
		TYPE_WSTRING,
		TYPE_COLOR,
		TYPE_UINT64,
		TYPE_COMPILED_INT_BYTE,
		TYPE_COMPILED_INT_0,
		TYPE_COMPILED_INT_1,
		TYPE_NUMTYPES
	};

	void* operator new(std::size_t nAllocSize)
	{
		static void* pKeyValuesSystem = nullptr;
		if (pKeyValuesSystem == nullptr)
		{
			KeyValuesSystemFn oKeyValuesSystem = (KeyValuesSystemFn)GetProcAddress(GetModuleHandle("vstdlib.dll"), ("KeyValuesSystem"));

			if (oKeyValuesSystem == nullptr)
				throw std::runtime_error(("failed to get keyvaluessystem export"));

			pKeyValuesSystem = oKeyValuesSystem();
		}

		return CallVFunc<void*>(pKeyValuesSystem, 2, nAllocSize);
	}

	void operator delete(void* pMemory)
	{
		static void* pKeyValuesSystem = nullptr;
		if (pKeyValuesSystem == nullptr)
		{
			KeyValuesSystemFn oKeyValuesSystem = (KeyValuesSystemFn)GetProcAddress(GetModuleHandle("vstdlib.dll"), ("KeyValuesSystem"));

			if (oKeyValuesSystem == nullptr)
				throw std::runtime_error(("failed to get keyvaluessystem export"));

			pKeyValuesSystem = oKeyValuesSystem();
		}

		CallVFunc<void>(pKeyValuesSystem, 3, pMemory);
	}

	const char* GetName()
	{
		static void* pKeyValuesSystem = nullptr;
		if (pKeyValuesSystem == nullptr)
		{
			KeyValuesSystemFn oKeyValuesSystem = (KeyValuesSystemFn)GetProcAddress(GetModuleHandle("vstdlib.dll"), ("KeyValuesSystem"));

			if (oKeyValuesSystem == nullptr)
				throw std::runtime_error(("failed to get keyvaluessystem export"));

			pKeyValuesSystem = oKeyValuesSystem();
		}

		typedef const char* (__thiscall* oGetName)(PVOID, int);
		return CallVFunc<const char*>(pKeyValuesSystem, 4, *(std::uint8_t*)((std::uintptr_t)this + 0x3) | (*(std::uint16_t*)((std::uintptr_t)this + 0x12) << 8));
	}

	int __forceinline GetInt(int default_value = 0) {
		int result{};

		switch (this->m_data_type) {
		case TYPE_STRING:
			result = atoi(this->m_value);
			break;
		case TYPE_WSTRING:
			result = _wtoi(this->m_ws_value);
			break;
		case TYPE_FLOAT:
			result = (signed int)floor(this->m_float_value);
			break;
		case TYPE_UINT64:
			result = 0;
			break;
		default:
			result = this->m_int_value;
			break;
		}

		return(result ? result : default_value);
	}

	void Init(const char* szKeyName)
	{
		m_ptr_value = NULL;

		m_has_escape_sequences = false;

		m_unk = 0;
		m_unk2 = 0;

		m_key_name = -1;
		m_data_type = TYPE_NONE;

		m_sub = NULL;
		m_peer = NULL;
		m_chain = NULL;

		m_value = NULL;
		m_ws_value = NULL;
	}

	void LoadFromBuffer(char const* szResourceName, const char* szBuffer, void* szFileSystem = nullptr, const char* szPathID = nullptr, void* pfnEvaluateSymbolProc = nullptr)
	{
		using LoadFromBufferFn = void(__thiscall*)(void*, const char*, const char*, void*, const char*, void*, void*);
		static auto oLoadFromBuffer = (LoadFromBufferFn)(pattern::Scan(XOR("client.dll"), ("55 8B EC 83 E4 F8 83 EC 34 53 8B 5D 0C 89 4C 24 04"))); // @xref: "KeyValues::LoadFromBuffer(%s%s%s): Begin"

		if (oLoadFromBuffer == nullptr)
			return;

		oLoadFromBuffer(this, szResourceName, szBuffer, szFileSystem, szPathID, pfnEvaluateSymbolProc, nullptr);
	}

	CKeyValues* FindKey(const char* szKeyName, bool bCreate)
	{
		using FindKeyFn = CKeyValues * (__thiscall*)(CKeyValues*, const char*, bool);
		static auto oFindKey = (FindKeyFn)(pattern::Scan(XOR("client.dll"), ("55 8B EC 83 EC 1C 53 8B D9 85 DB")));
		return oFindKey(this, szKeyName, bCreate);
	}

	void SetString(const char* szKeyName, const char* szValue)
	{
		CKeyValues* pKey = FindKey(szKeyName, true);

		if (pKey == nullptr)
			return;

		using SetStringFn = void(__thiscall*)(void*, const char*);
		static auto oSetString = (SetStringFn)(pattern::Scan(XOR("client.dll"), ("55 8B EC A1 ? ? ? ? 53 56 57 8B F9 8B 08 8B 01")));
		oSetString(pKey, szValue);
	}

	void SetInt(const char* szKeyName, int iValue)
	{
		CKeyValues* pKey = FindKey(szKeyName, true);

		if (pKey == nullptr)
			return;

		*(int*)((uintptr_t)pKey + 0xC) = iValue;
		*(char*)((uintptr_t)pKey + 0x10) = 2;
	}

	inline void SetBool(const char* szKeyName, bool bValue)
	{
		SetInt(szKeyName, bValue ? 1 : 0);
	}

private:

	int m_key_name; // keyname is a symbol defined in KeyValuesSystem

	int m_unk;
	int m_unk2;

	char* m_value;
	wchar_t* m_ws_value;

	union
	{
		int m_int_value;
		float m_float_value;
		void* m_ptr_value;
		unsigned char m_color[4];
	};

	char       m_data_type;
	char       m_has_escape_sequences; // true, if while parsing this KeyValue, Escape Sequences are used (default false)
	char       m_evaluate_conditionals; // true, if while parsing this KeyValue, conditionals blocks are evaluated (default true)
	char       unused[1];

	CKeyValues* m_peer;
	CKeyValues* m_sub;
	CKeyValues* m_chain;
}; // Size: 0x0024

class IMaterialSystem {
public:
	i_material *find_material( char const *material_name, const char *group_name, bool complain = true, const char *complain_prefix = 0 ) {
		using fn = i_material * ( __thiscall * )( IMaterialSystem *, char const *, const char *, bool, const char * );
		return ( *( fn ** ) this )[ 84 ]( this, material_name, group_name, complain, complain_prefix );
	}

	i_material* CreateMaterial(const char* szName, CKeyValues* pKeyValues)
	{
		using fn = i_material*(__thiscall*)(IMaterialSystem*, const char*, CKeyValues*);
		return (*(fn**)this)[83](this, szName, pKeyValues);
	}

	material_handle_t first_material() {
		using fn = material_handle_t( __thiscall * )( IMaterialSystem * );
		return ( *( fn ** ) this )[ 86 ]( this );
	}
	material_handle_t next_material( material_handle_t handle ) {
		using fn = material_handle_t( __thiscall * )( IMaterialSystem *, material_handle_t );
		return ( *( fn ** ) this )[ 87 ]( this, handle );
	}
	material_handle_t invalid_material_handle() {
		using fn = material_handle_t( __thiscall * )( IMaterialSystem * );
		return ( *( fn ** ) this )[ 88 ]( this );
	}
	i_material *get_material( material_handle_t handle ) {
		using fn = i_material * ( __thiscall * )( IMaterialSystem *, material_handle_t );
		return ( *( fn ** ) this )[ 89 ]( this, handle );
	}
	int	get_materials_count() {
		using fn = int( __thiscall * )( IMaterialSystem * );
		return ( *( fn ** ) this )[ 90 ]( this );
	}
};

#include "mips2c_table.h"

#include "common/log/log.h"
#include "common/symbols.h"

#include "game/kernel/common/kmalloc.h"
#include "game/kernel/common/kscheme.h"
#include "game/kernel/jak1/kscheme.h"
#include "game/kernel/jak2/kscheme.h"
#include "game/runtime.h"

extern "C" {
void _mips2c_call_linux();
void _mips2c_call_windows();
}

// clang-format off
namespace Mips2C {

namespace jak1 {
namespace draw_string { extern void link(); }
namespace sp_init_fields { extern void link(); }
namespace particle_adgif { extern void link(); }
namespace sp_launch_particles_var { extern void link(); }
namespace sp_process_block_3d { extern void link(); }
namespace sp_process_block_2d { extern void link(); }
namespace draw_large_polygon { extern void link(); }
namespace init_sky_regs { extern void link(); }
namespace clip_polygon_against_positive_hyperplane { extern void link(); }
namespace render_sky_quad { extern void link(); }
namespace render_sky_tri { extern void link(); }
namespace set_tex_offset { extern void link(); }
namespace set_sky_vf27 { extern void link(); }
namespace set_sky_vf23_value { extern void link(); }
namespace adgif_shader_texture_with_update { extern void link(); }
namespace init_boundary_regs { extern void link(); }
namespace render_boundary_quad { extern void link(); }
namespace render_boundary_tri { extern void link(); }
namespace draw_boundary_polygon { extern void link(); }
namespace draw_inline_array_tfrag { extern void link(); }
namespace stats_tfrag_asm { extern void link(); }
namespace time_of_day_interp_colors_scratch { extern void link(); }
namespace collide_do_primitives { extern void link(); }
namespace moving_sphere_triangle_intersect { extern void link(); }
namespace method_12_collide_mesh { extern void link(); }
namespace method_11_collide_mesh { extern void link(); }
namespace collide_probe_node { extern void link(); }
namespace collide_probe_instance_tie { extern void link(); }
namespace method_26_collide_cache { extern void link(); }
namespace method_32_collide_cache { extern void link(); }
namespace pc_upload_collide_frag { extern void link(); }
namespace method_28_collide_cache { extern void link(); }
namespace method_27_collide_cache { extern void link(); }
namespace method_29_collide_cache { extern void link(); }
namespace method_12_collide_shape_prim_mesh { extern void link(); }
namespace method_14_collide_shape_prim_mesh { extern void link(); }
namespace method_13_collide_shape_prim_mesh { extern void link(); }
namespace method_30_collide_cache { extern void link(); }
namespace method_9_collide_cache_prim { extern void link(); }
namespace method_10_collide_cache_prim { extern void link(); }
namespace method_10_collide_puss_work { extern void link(); }
namespace method_9_collide_puss_work { extern void link(); }
namespace method_15_collide_mesh { extern void link(); }
namespace method_14_collide_mesh { extern void link(); }
namespace method_16_collide_edge_work { extern void link(); }
namespace method_15_collide_edge_work { extern void link(); }
namespace method_10_collide_edge_hold_list { extern void link(); }
namespace method_18_collide_edge_work { extern void link(); }
namespace calc_animation_from_spr { extern void link(); }
namespace bones_mtx_calc { extern void link(); }
namespace cspace_parented_transformq_joint { extern void link(); }
namespace draw_bones_merc { extern void link(); }
namespace draw_bones_check_longest_edge_asm { extern void link(); }
namespace blerc_execute { extern void link(); }
namespace setup_blerc_chains_for_one_fragment { extern void link(); }
namespace generic_merc_init_asm { extern void link(); }
namespace generic_merc_execute_asm { extern void link(); }
namespace mercneric_convert { extern void link(); }
namespace generic_prepare_dma_double { extern void link(); }
namespace generic_light_proc { extern void link(); }
namespace generic_envmap_proc { extern void link(); }
namespace high_speed_reject { extern void link(); }
namespace generic_prepare_dma_single { extern void link(); }
namespace ripple_create_wave_table { extern void link(); }
namespace ripple_execute_init { extern void link(); }
namespace ripple_apply_wave_table { extern void link(); }
namespace ripple_matrix_scale { extern void link(); }
namespace init_ocean_far_regs { extern void link(); }
namespace render_ocean_quad { extern void link(); }
namespace draw_large_polygon_ocean { extern void link(); }
namespace ocean_interp_wave { extern void link(); }
namespace ocean_generate_verts { extern void link(); }
namespace shadow_execute { extern void link(); }
namespace shadow_add_double_edges { extern void link(); }
namespace shadow_add_double_tris { extern void link(); }
namespace shadow_add_single_edges { extern void link(); }
namespace shadow_add_facing_single_tris { extern void link(); }
namespace shadow_add_verts { extern void link(); }
namespace shadow_find_double_edges { extern void link(); }
namespace shadow_find_facing_double_tris { extern void link(); }
namespace shadow_find_single_edges { extern void link(); }
namespace shadow_find_facing_single_tris { extern void link(); }
namespace shadow_init_vars { extern void link(); }
namespace shadow_scissor_top { extern void link(); }
namespace shadow_scissor_edges { extern void link(); }
namespace shadow_calc_dual_verts { extern void link(); }
namespace shadow_xform_verts { extern void link(); }
namespace draw_inline_array_instance_tie { extern void link(); }
namespace draw_inline_array_prototype_tie_generic_asm { extern void link(); }
namespace generic_tie_dma_to_spad_sync { extern void link(); }
namespace generic_envmap_dproc { extern void link(); }
namespace generic_interp_dproc { extern void link(); }
namespace generic_no_light_dproc { extern void link(); }
namespace generic_tie_convert { extern void link(); }
}  // namespace jak1

namespace jak2 {
namespace collide_do_primitives { extern void link(); }
namespace moving_sphere_triangle_intersect { extern void link(); }
namespace calc_animation_from_spr { extern void link(); }
namespace cspace_parented_transformq_joint { extern void link(); }
namespace draw_string_asm { extern void link(); }
namespace draw_string { extern void link(); }
namespace get_string_length { extern void link(); }
}
// clang-format on

LinkedFunctionTable gLinkedFunctionTable;
Rng gRng;
PerGameVersion<std::unordered_map<std::string, std::vector<void (*)()>>> gMips2CLinkCallbacks = {
    //////// JAK 1
    {{"font", {jak1::draw_string::link}},
     {"sparticle-launcher",
      {jak1::sp_init_fields::link, jak1::particle_adgif::link,
       jak1::sp_launch_particles_var::link}},
     {"sparticle", {jak1::sp_process_block_3d::link, jak1::sp_process_block_2d::link}},
     {"texture", {jak1::adgif_shader_texture_with_update::link}},
     {"sky-tng",
      {jak1::draw_large_polygon::link, jak1::init_sky_regs::link,
       jak1::clip_polygon_against_positive_hyperplane::link, jak1::render_sky_quad::link,
       jak1::render_sky_tri::link, jak1::set_tex_offset::link, jak1::set_sky_vf27::link,
       jak1::set_sky_vf23_value::link}},
     {"load-boundary",
      {jak1::init_boundary_regs::link, jak1::render_boundary_quad::link,
       jak1::render_boundary_tri::link, jak1::draw_boundary_polygon::link}},
     {"tfrag", {jak1::draw_inline_array_tfrag::link, jak1::stats_tfrag_asm::link}},
     {"time-of-day", {jak1::time_of_day_interp_colors_scratch::link}},
     {"collide-func",
      {jak1::collide_do_primitives::link, jak1::moving_sphere_triangle_intersect::link}},
     {"collide-probe", {jak1::collide_probe_node::link, jak1::collide_probe_instance_tie::link}},
     {"collide-mesh",
      {jak1::method_12_collide_mesh::link, jak1::method_11_collide_mesh::link,
       jak1::method_15_collide_mesh::link, jak1::method_14_collide_mesh::link}},
     {"collide-cache",
      {jak1::method_26_collide_cache::link, jak1::method_32_collide_cache::link,
       jak1::pc_upload_collide_frag::link, jak1::method_28_collide_cache::link,
       jak1::method_27_collide_cache::link, jak1::method_29_collide_cache::link,
       jak1::method_12_collide_shape_prim_mesh::link, jak1::method_14_collide_shape_prim_mesh::link,
       jak1::method_13_collide_shape_prim_mesh::link, jak1::method_30_collide_cache::link,
       jak1::method_9_collide_cache_prim::link, jak1::method_10_collide_cache_prim::link,
       jak1::method_10_collide_puss_work::link, jak1::method_9_collide_puss_work::link}},
     {"collide-edge-grab",
      {jak1::method_16_collide_edge_work::link, jak1::method_15_collide_edge_work::link,
       jak1::method_10_collide_edge_hold_list::link, jak1::method_18_collide_edge_work::link}},
     {"joint", {jak1::calc_animation_from_spr::link, jak1::cspace_parented_transformq_joint::link}},
     {"bones",
      {jak1::bones_mtx_calc::link, jak1::draw_bones_merc::link,
       jak1::draw_bones_check_longest_edge_asm::link}},
     {"merc-blend-shape",
      {jak1::blerc_execute::link, jak1::setup_blerc_chains_for_one_fragment::link}},
     {"generic-merc",
      {jak1::generic_merc_init_asm::link, jak1::generic_merc_execute_asm::link,
       jak1::mercneric_convert::link, jak1::high_speed_reject::link}},
     {"generic-effect",
      {jak1::generic_prepare_dma_double::link, jak1::generic_light_proc::link,
       jak1::generic_envmap_proc::link, jak1::generic_prepare_dma_single::link,
       jak1::generic_envmap_dproc::link, jak1::generic_interp_dproc::link,
       jak1::generic_no_light_dproc::link}},
     {"ripple",
      {jak1::ripple_execute_init::link, jak1::ripple_create_wave_table::link,
       jak1::ripple_apply_wave_table::link, jak1::ripple_matrix_scale::link}},
     {"ocean",
      {jak1::init_ocean_far_regs::link, jak1::render_ocean_quad::link,
       jak1::draw_large_polygon_ocean::link}},
     {"ocean-vu0", {jak1::ocean_interp_wave::link, jak1::ocean_generate_verts::link}},
     {"shadow-cpu",
      {jak1::shadow_execute::link, jak1::shadow_add_double_edges::link,
       jak1::shadow_add_double_tris::link, jak1::shadow_add_single_edges::link,
       jak1::shadow_add_facing_single_tris::link, jak1::shadow_add_verts::link,
       jak1::shadow_find_double_edges::link, jak1::shadow_find_facing_double_tris::link,
       jak1::shadow_find_single_edges::link, jak1::shadow_find_facing_single_tris::link,
       jak1::shadow_init_vars::link, jak1::shadow_scissor_top::link,
       jak1::shadow_scissor_edges::link, jak1::shadow_calc_dual_verts::link,
       jak1::shadow_xform_verts::link}},
     {"tie-methods",
      {jak1::draw_inline_array_instance_tie::link,
       jak1::draw_inline_array_prototype_tie_generic_asm::link}},
     {"generic-tie", {jak1::generic_tie_dma_to_spad_sync::link, jak1::generic_tie_convert::link}}},
    /////////// JAK 2
    {{"collide-func",
      {jak2::collide_do_primitives::link, jak2::moving_sphere_triangle_intersect::link}},
     {"joint", {jak2::calc_animation_from_spr::link, jak2::cspace_parented_transformq_joint::link}},
     {"font",
      {jak2::draw_string::link, jak2::get_string_length::link, jak2::draw_string_asm::link}}},
};

void LinkedFunctionTable::reg(const std::string& name, u64 (*exec)(void*), u32 stack_size) {
  const auto& it = m_executes.insert({name, {exec, Ptr<u8>()}});
  if (!it.second) {
    lg::error("MIPS2C Function {} is registered multiple times, ignoring later registrations.",
              name);
  }

  // this is short stub that will jump to the appropriate function.
  Ptr<u8> jump_to_asm;
  switch (g_game_version) {
    case GameVersion::Jak1:
      jump_to_asm = Ptr<u8>(::jak1::alloc_heap_object(s7.offset + jak1_symbols::FIX_SYM_GLOBAL_HEAP,
                                                      *(s7 + jak1_symbols::FIX_SYM_FUNCTION_TYPE),
                                                      0x40, UNKNOWN_PP));
      break;
    case GameVersion::Jak2:
      jump_to_asm = Ptr<u8>(::jak2::alloc_heap_object(
          s7.offset + jak2_symbols::FIX_SYM_GLOBAL_HEAP,
          ::jak2::u32_in_fixed_sym(jak2_symbols::FIX_SYM_FUNCTION_TYPE), 0x40, UNKNOWN_PP));
      break;
    default:
      ASSERT(false);
  }

  it.first->second.goal_trampoline = jump_to_asm;

  u8* ptr = jump_to_asm.c();

  {
    // linux

    // push the function
    u64 addr = (u64)exec;
    *ptr = 0x48;
    ptr++;
    *ptr = 0xb8;
    ptr++;
    memcpy(ptr, &addr, 8);
    ptr += 8;
    *ptr = 0x50;
    ptr++;

    // push the stack size
    addr = stack_size;
    *ptr = 0x48;
    ptr++;
    *ptr = 0xb8;
    ptr++;
    memcpy(ptr, &addr, 8);
    ptr += 8;
    *ptr = 0x50;
    ptr++;

    // call the other function
#ifdef __linux__
    addr = (u64)_mips2c_call_linux;
#elif _WIN32
    addr = (u64)_mips2c_call_windows;
#endif

    *ptr = 0x48;
    ptr++;
    *ptr = 0xb8;
    ptr++;
    memcpy(ptr, &addr, 8);
    ptr += 8;

    // jumps to the mips2c call, which will return to the caller of this stub.
    *ptr = 0xff;
    ptr++;
    *ptr = 0xe0;
  }
}

u32 LinkedFunctionTable::get(const std::string& name) {
  auto it = m_executes.find(name);
  if (it == m_executes.end()) {
    ASSERT(false);
  }
  return it->second.goal_trampoline.offset;
}
}  // namespace Mips2C
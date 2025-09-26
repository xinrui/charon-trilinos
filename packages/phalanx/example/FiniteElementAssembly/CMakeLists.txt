cmake_minimum_required(VERSION 3.10)
project(FiniteElementAssemblyExample)

# 添加头文件搜索路径
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/evaluators
    ${CMAKE_CURRENT_SOURCE_DIR}/auxiliary_tests
    ${CMAKE_BINARY_DIR}/packages/kokkos
    ${CMAKE_SOURCE_DIR}/packages/kokkos/containers/src
    ${CMAKE_BINARY_DIR}/packages/kokkos/core/src
    ${CMAKE_SOURCE_DIR}/packages/kokkos/core/src
    ${CMAKE_SOURCE_DIR}/packages/kokkos/tpls/desul/include
    ${CMAKE_SOURCE_DIR}/packages/kokkos/tpls/mdspan/include
    ${CMAKE_BINARY_DIR}/packages/kokkos-kernels
    ${CMAKE_BINARY_DIR}/packages/kokkos-kernels/src
    ${CMAKE_SOURCE_DIR}/packages/kokkos-kernels/src
    ${CMAKE_SOURCE_DIR}/packages/kokkos-kernels/src/common
    ${CMAKE_SOURCE_DIR}/packages/kokkos-kernels/src/sparse
    ${CMAKE_BINARY_DIR}/packages/phalanx/src
    ${CMAKE_SOURCE_DIR}/packages/phalanx/src
    ${CMAKE_BINARY_DIR}/packages/sacado/src
    ${CMAKE_SOURCE_DIR}/packages/sacado/src
    ${CMAKE_SOURCE_DIR}/packages/sacado/src/mpl
    ${CMAKE_SOURCE_DIR}/packages/sacado/src/new_design
    ${CMAKE_SOURCE_DIR}/packages/teuchos/comm/src
    ${CMAKE_BINARY_DIR}/packages/teuchos/core/src
    ${CMAKE_SOURCE_DIR}/packages/teuchos/core/src
    ${CMAKE_SOURCE_DIR}/packages/teuchos/numerics/src
    ${CMAKE_BINARY_DIR}/packages/teuchos/kokkoscomm/src
    ${CMAKE_SOURCE_DIR}/packages/teuchos/kokkoscomm/src
    ${CMAKE_BINARY_DIR}/packages/teuchos/kokkoscompat/src
    ${CMAKE_SOURCE_DIR}/packages/teuchos/kokkoscompat/src
    ${CMAKE_BINARY_DIR}/packages/teuchos/parameterlist/src
    ${CMAKE_SOURCE_DIR}/packages/teuchos/parameterlist/src
)

# 主例子源文件列表
set(example_fem_SOURCES
    MyTraits.hpp
    ExplicitTemplateInstantiation.hpp
    Dimension.hpp
    Workset.hpp
    WorksetBuilder.hpp
    Mesh.hpp
    Mesh.cpp
    LinearObjectFactory.hpp
    CommandLineParser.hpp
    PrintValues.hpp
    evaluators/Constant.hpp
    evaluators/Constant_Def.hpp
    evaluators/Constant.cpp
    evaluators/IntegrateDiffusionTerm.hpp
    evaluators/IntegrateDiffusionTerm_Def.hpp
    evaluators/IntegrateDiffusionTerm.cpp
    evaluators/IntegrateSourceTerm.hpp
    evaluators/IntegrateSourceTerm_Def.hpp
    evaluators/IntegrateSourceTerm.cpp
    evaluators/GatherSolution.hpp
    evaluators/GatherSolution_Def.hpp
    evaluators/GatherSolution.cpp
    evaluators/ProjectValueToQP.hpp
    evaluators/ProjectValueToQP_Def.hpp
    evaluators/ProjectValueToQP.cpp
    evaluators/ProjectGradientToQP.hpp
    evaluators/ProjectGradientToQP_Def.hpp
    evaluators/ProjectGradientToQP.cpp
    evaluators/ZeroContributedField.hpp
    evaluators/ZeroContributedField_Def.hpp
    evaluators/ZeroContributedField.cpp
    evaluators/ScatterResidual.hpp
    evaluators/ScatterResidual_Def.hpp
    evaluators/ScatterResidual.cpp
)

# 编译主例子可执行文件
add_executable(example_finite_element_assembly FiniteElementAssembly.cpp ${example_fem_SOURCES})

# 辅助测试源文件列表
set(example_element_linear_2D_SOURCES
    Mesh.hpp
    Mesh.cpp
    Workset.hpp
    WorksetBuilder.hpp
)

# 编译辅助测试可执行文件
#add_executable(example_mesh_aux_test auxiliary_tests/Example_FEM_Mesh_AuxTest.cpp ${example_element_linear_2D_SOURCES})
#add_executable(example_workset_aux_test auxiliary_tests/Example_FEM_Workset_AuxTest.cpp ${example_element_linear_2D_SOURCES})
#add_executable(example_lof_aux_test auxiliary_tests/Example_FEM_LinearObjectFactory_AuxTest.cpp ${example_element_linear_2D_SOURCES})

# 如有需要，可以在此处添加链接库
target_link_libraries(example_finite_element_assembly phalanx kokkoscore kokkoskernels sacado)
#target_link_libraries(example_mesh_aux_test phalanx kokkos kokkoskernels sacado )
#target_link_libraries(example_workset_aux_test phalanx kokkos kokkoskernels sacado)
#target_link_libraries(example_lof_aux_test phalanx kokkos kokkoskernels sacado)
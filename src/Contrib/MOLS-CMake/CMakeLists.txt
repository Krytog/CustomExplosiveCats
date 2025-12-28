add_library(mols_includes INTERFACE)

target_include_directories(mols_includes INTERFACE
    ${BASE_SRC_PATH}/Contrib/MOLS/src
)

macro(add_ldap_executable name)
  # add executable
  add_executable(${name} ${ARGN})

  # add install target
  set_target_properties(${name} PROPERTIES OUTPUT_NAME ldap-${name})
  install(TARGETS ${name} DESTINATION bin
      PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)

  # copy binary
  add_custom_command(TARGET ${name} POST_BUILD COMMAND
      ${CMAKE_COMMAND} ARGS -E copy
        $<TARGET_FILE:${name}>
        ${CMAKE_BINARY_DIR}/bin/$<TARGET_FILE_NAME:${name}>
      COMMENT "Copy ${name} to ${CMAKE_BINARY_DIR}/bin")

endmacro(add_ldap_executable)


add_subdirectory(utils)

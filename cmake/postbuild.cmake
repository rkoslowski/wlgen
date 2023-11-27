macro(postbuild target)
add_custom_command(
	TARGET ${target}
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
            ${PROJECT_PATH}/dependencies/python310.dll
            ${CMAKE_CURRENT_BINARY_DIR}/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>/python310.dll
)
add_custom_command(
	TARGET ${target}
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_PATH}/dependencies/tmp
            ${CMAKE_CURRENT_BINARY_DIR}/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>/tmp
)
add_custom_command(
	TARGET ${target}
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_PATH}/dependencies/rsrc
            ${CMAKE_CURRENT_BINARY_DIR}/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>/rsrc
)
add_custom_command(
	TARGET ${target}
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_PATH}/dependencies/python3_10
            ${CMAKE_CURRENT_BINARY_DIR}/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>/python3_10
)
endmacro()
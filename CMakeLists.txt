cmake_minimum_required (VERSION 3.10.2)


if(NOT DEFINED pluginname)
    set(pluginname gipSlider)
endif()



list(APPEND PLUGIN_SRCS
			${PLUGINS_DIR}/${pluginname}/src/gipSlider.cpp
)

list(APPEND PLUGIN_INCLUDES
			${PLUGINS_DIR}/${pluginname}/src
)

apps += Sequence::App
app_headers += apps/sequence/app.h

app_sequence_test_src = $(addprefix apps/sequence/,\
 \
)

app_sequence_src = $(addprefix apps/sequence/,\
  app.cpp \
  graph/cobweb_controller.cpp \
  graph/cobweb_graph_view.cpp \
  graph/curve_parameter_controller.cpp \
  graph/curve_view_range.cpp \
  graph/go_to_parameter_controller.cpp \
  graph/graph_controller.cpp \
  graph/graph_view.cpp \
  graph/term_sum_controller.cpp \
  list/editable_sequence_cell.cpp \
  list/list_controller.cpp \
  list/list_parameter_controller.cpp \
  list/sequence_cell.cpp \
  list/sequence_toolbox_data_source.cpp \
  list/type_parameter_controller.cpp \
  list/vertical_sequence_title_cell.cpp \
  values/interval_parameter_controller.cpp \
  values/sequence_column_parameter_controller.cpp \
  values/sum_column_parameter_controller.cpp \
  values/values_controller.cpp \
)

app_sequence_src += $(app_sequence_test_src)
apps_src += $(app_sequence_src)

i18n_files += $(call i18n_without_universal_for,sequence/i18n/base)

tests_src += $(addprefix apps/sequence/test/,\
  sequence.cpp\
)

$(eval $(call depends_on_image,apps/sequence/app.cpp,apps/sequence/sequence_icon.png))

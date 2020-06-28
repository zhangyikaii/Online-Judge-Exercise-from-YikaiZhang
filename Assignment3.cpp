/*

数据说明:
breast-w:
	关系名称:
		wisconsin-breast-cancer
	特征说明:
		Clump_Thickness integer [1,10]
		Cell_Size_Uniformity integer [1,10]
		Cell_Shape_Uniformity integer [1,10]
		Marginal_Adhesion integer [1,10]
		Single_Epi_Cell_Size integer [1,10]
		Bare_Nuclei integer [1,10]
		Bland_Chromatin integer [1,10]
		Normal_Nucleoli integer [1,10]
		Mitoses integer [1,10]
		Class { benign, malignant}

colic:
	关系名称:
		horse-colic
	特征说明:
		'surgery' { yes, no}
		'Age' { adult, young}
		'rectal_temperature' real
		'pulse' real
		'respiratory_rate' real
		'temp_extremities' { normal, warm, cool, cold}
		'peripheral_pulse' { normal, increased, reduced, absent}
		'mucous_membranes' { 'normal pink', 'bright pink', 'pale pink', 'pale cyanotic', 'bright red', 'dark cyanotic'}
		'capillary_refill_time' { '<3', '>=3', 'meaning unknown'}
		'pain' { 'alert no pain', depressed, 'intermittent mild pain', 'intermittent severe pain', 'continuous severe pain'}
		'peristalsis' { hypermotile, normal, hypomotile, absent}
		'abdominal_distension' { none, slight, moderate, severe}
		'nasogastric_tube' { none, slight, significant}
		'nasogastric_reflux' { none, '>1l', '<1l'}
		'nasogastric_reflux_PH' real
		'rectal_examination' { normal, increased, decreased, absent}
		'abdomen' { normal, other, 'firm feces in large intestine', 'distended small intestine', 'distended large intestine'}
		'packed_cell_volume' real
		'total_protein' real
		'abdominocentesis_appearance' { clear, cloudy, serosanguinous}
		'abdomcentesis_total_protein' real
		'outcome' { lived, died, euthanized}
		'surgical_lesion' { yes, no}
	*/
////////////////////////////////////////////////////////
//
// GEM - Graphics Environment for Multimedia
//
// Implementation file
//
// Copyright (c) 2002-2011 IOhannes m zmölnig. forum::für::umläute. IEM. zmoelnig@iem.at
//	zmoelnig@iem.kug.ac.at
//  For information on usage and redistribution, and for a DISCLAIMER
//  *  OF ALL WARRANTIES, see the file, "GEM.LICENSE.TERMS"
//
//  this file has been generated...
////////////////////////////////////////////////////////

#include "GEMglTexCoord4sv.h"

CPPEXTERN_NEW_WITH_FOUR_ARGS ( GEMglTexCoord4sv , t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT);

/////////////////////////////////////////////////////////
//
// GEMglTexCoord4sv
//
/////////////////////////////////////////////////////////
// Constructor
//
GEMglTexCoord4sv :: GEMglTexCoord4sv	(t_floatarg arg0, t_floatarg arg1, t_floatarg arg2, t_floatarg arg3) {
vMess(arg0, arg1, arg2, arg3);
	m_inlet = inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("v"));
}
/////////////////////////////////////////////////////////
// Destructor
//
GEMglTexCoord4sv :: ~GEMglTexCoord4sv () {
	inlet_free(m_inlet);
}

/////////////////////////////////////////////////////////
// Render
//
void GEMglTexCoord4sv :: render(GemState *state) {
	glTexCoord4sv (v);
}

/////////////////////////////////////////////////////////
// variable
//
void GEMglTexCoord4sv :: vMess (t_float arg0, t_float arg1, t_float arg2, t_float arg3) {	// FUN
	v[0]=static_cast<GLshort>(arg0);
	v[1]=static_cast<GLshort>(arg1);
	v[2]=static_cast<GLshort>(arg2);
	v[3]=static_cast<GLshort>(arg3);
	setModified();
}

/////////////////////////////////////////////////////////
// static member functions
//

void GEMglTexCoord4sv :: obj_setupCallback(t_class *classPtr) {
	 class_addmethod(classPtr, reinterpret_cast<t_method>(&GEMglTexCoord4sv::vMessCallback),  	gensym("v"), A_DEFFLOAT, A_DEFFLOAT, A_DEFFLOAT, A_DEFFLOAT, A_NULL);
}

void GEMglTexCoord4sv :: vMessCallback (void* data, t_float arg0, t_float arg1, t_float arg2, t_float arg3) {
	GetMyClass(data)->vMess ( arg0, arg1, arg2, arg3);
}

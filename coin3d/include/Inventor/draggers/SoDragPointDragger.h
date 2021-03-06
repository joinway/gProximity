/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2002 by Systems in Motion. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  version 2.1 as published by the Free Software Foundation. See the
 *  file LICENSE.LGPL at the root directory of the distribution for
 *  more details.
 *
 *  If you want to use Coin for applications not compatible with the
 *  LGPL, please contact SIM to acquire a Professional Edition license.
 *
 *  Systems in Motion, Prof Brochs gate 6, 7030 Trondheim, NORWAY
 *  http://www.sim.no support@sim.no Voice: +47 22114160 Fax: +47 22207097
 *
\**************************************************************************/

#ifndef COIN_SODRAGPOINTDRAGGER_H
#define COIN_SODRAGPOINTDRAGGER_H

#include <Inventor/draggers/SoDragger.h>
#include <Inventor/fields/SoSFVec3f.h>

class SoSensor;
class SoFieldSensor;


class COIN_DLL_API SoDragPointDragger : public SoDragger
{
	typedef SoDragger inherited;
	
	SO_KIT_HEADER(SoDragPointDragger);
	
	SO_KIT_CATALOG_ENTRY_HEADER(noRotSep);
	SO_KIT_CATALOG_ENTRY_HEADER(planeFeedbackSep);
	SO_KIT_CATALOG_ENTRY_HEADER(planeFeedbackSwitch);
	SO_KIT_CATALOG_ENTRY_HEADER(planeFeedbackTranslation);
	SO_KIT_CATALOG_ENTRY_HEADER(rotX);
	SO_KIT_CATALOG_ENTRY_HEADER(rotXSep);
	SO_KIT_CATALOG_ENTRY_HEADER(rotY);
	SO_KIT_CATALOG_ENTRY_HEADER(rotYSep);
	SO_KIT_CATALOG_ENTRY_HEADER(rotZ);
	SO_KIT_CATALOG_ENTRY_HEADER(rotZSep);
	SO_KIT_CATALOG_ENTRY_HEADER(xFeedback);
	SO_KIT_CATALOG_ENTRY_HEADER(xFeedbackSep);
	SO_KIT_CATALOG_ENTRY_HEADER(xFeedbackSwitch);
	SO_KIT_CATALOG_ENTRY_HEADER(xFeedbackTranslation);
	SO_KIT_CATALOG_ENTRY_HEADER(xTranslator);
	SO_KIT_CATALOG_ENTRY_HEADER(xTranslatorSwitch);
	SO_KIT_CATALOG_ENTRY_HEADER(xyFeedback);
	SO_KIT_CATALOG_ENTRY_HEADER(xyTranslator);
	SO_KIT_CATALOG_ENTRY_HEADER(xyTranslatorSwitch);
	SO_KIT_CATALOG_ENTRY_HEADER(xzFeedback);
	SO_KIT_CATALOG_ENTRY_HEADER(xzTranslator);
	SO_KIT_CATALOG_ENTRY_HEADER(xzTranslatorSwitch);
	SO_KIT_CATALOG_ENTRY_HEADER(yFeedback);
	SO_KIT_CATALOG_ENTRY_HEADER(yFeedbackSep);
	SO_KIT_CATALOG_ENTRY_HEADER(yFeedbackSwitch);
	SO_KIT_CATALOG_ENTRY_HEADER(yFeedbackTranslation);
	SO_KIT_CATALOG_ENTRY_HEADER(yTranslator);
	SO_KIT_CATALOG_ENTRY_HEADER(yTranslatorSwitch);
	SO_KIT_CATALOG_ENTRY_HEADER(yzFeedback);
	SO_KIT_CATALOG_ENTRY_HEADER(yzTranslator);
	SO_KIT_CATALOG_ENTRY_HEADER(yzTranslatorSwitch);
	SO_KIT_CATALOG_ENTRY_HEADER(zFeedback);
	SO_KIT_CATALOG_ENTRY_HEADER(zFeedbackSep);
	SO_KIT_CATALOG_ENTRY_HEADER(zFeedbackSwitch);
	SO_KIT_CATALOG_ENTRY_HEADER(zFeedbackTranslation);
	SO_KIT_CATALOG_ENTRY_HEADER(zTranslator);
	SO_KIT_CATALOG_ENTRY_HEADER(zTranslatorSwitch);
	
	
public:
	static void initClass(void);
	SoDragPointDragger(void);
	
	void setJumpLimit(const float limit);
	float getJumpLimit(void) const;
	void showNextDraggerSet(void);
	
	SoSFVec3f translation;
	
protected:
	~SoDragPointDragger();
	virtual SbBool setUpConnections(SbBool onoff, SbBool doitalways = FALSE);
	virtual void setDefaultOnNonWritingFields(void);
	
	void dragStart(void);
	void drag(void);
	void dragFinish(void);
	
	static void startCB(void * f, SoDragger * d);
	static void motionCB(void * f, SoDragger * d);
	static void finishCB(void * f, SoDragger * d);
	static void metaKeyChangeCB(void * f, SoDragger * d);
	static void fieldSensorCB(void * f, SoSensor * s);
	static void valueChangedCB(void * f, SoDragger * d);
	
	SoFieldSensor * fieldSensor;
	
private:
	void registerDragger(SoDragger *dragger);
	void unregisterDragger(const char *name);
	void updateSwitchNodes();
	int currAxis;
	float jumpLimit;
};

#endif // !COIN_SODRAGPOINTDRAGGER_H

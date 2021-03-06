#ifndef _DW9761OFILM_H
#define _DW9761OFILM_H

#include <linux/ioctl.h>
//#include "kd_imgsensor.h"

#define DW9761OFILMAF_MAGIC 'A'
//IOCTRL(inode * ,file * ,cmd ,arg )


//Structures
typedef struct {
//current position
u32 u4CurrentPosition;
//macro position
u32 u4MacroPosition;
//Infiniti position
u32 u4InfPosition;
//Motor Status
bool          bIsMotorMoving;
//Motor Open?
bool          bIsMotorOpen;
//Support SR?
bool          bIsSupportSR;
} stDW9761OFILMAF_MotorInfo;


//Structures
//#define LensdrvCM3
#ifdef LensdrvCM3
typedef struct {
	//APERTURE , won't be supported on most devices.
	float Aperture;
	//FILTER_DENSITY, won't be supported on most devices.
	float FilterDensity;
	//FOCAL_LENGTH, lens optical zoom setting. won't be supported on most devices.
	float FocalLength;
	//FOCAL_DISTANCE, current focus distance, lens to objects.
	float FocalDistance;
	//OPTICAL_STABILIZATION_MODE 
	u16 u4OIS_Mode;
	//FACING
	u16 Facing;
	//Optical axis angle,  optical axis is perpendicular to LCM, usually is  {0,0}.
	float OpticalAxisAng[2];
	//Optical axis position (mm),  usually is  {0,0,0}.
	float Position[3];
	//Focus range, DOF, 
	float FocusRange;
	//State
	u16 State;
	//INFO
	float InfoAvalibleMinFocusDistance;
	float InfoAvalibleApertures;
	float InfoAvalibleFilterDensity;
	u16 InfoAvalibleOptStabilization;
	float InfoAvalibleFocalLength;
	float InfoAvalibleHypeDistance;
}stDW9761OFILMAF_MotorMETAInfo;
#endif

//Control commnad
//S means "set through a ptr"
//T means "tell by a arg value"
//G means "get by a ptr"             
//Q means "get by return a value"
//X means "switch G and S atomically"
//H means "switch T and Q atomically"
#define DW9761OFILMAFIOC_G_MOTORINFO _IOR(DW9761OFILMAF_MAGIC,0,stDW9761OFILMAF_MotorInfo)

#define DW9761OFILMAFIOC_T_MOVETO _IOW(DW9761OFILMAF_MAGIC,1,u32)

#define DW9761OFILMAFIOC_T_SETINFPOS _IOW(DW9761OFILMAF_MAGIC,2,u32)

#define DW9761OFILMAFIOC_T_SETMACROPOS _IOW(DW9761OFILMAF_MAGIC,3,u32)
#ifdef LensdrvCM3
#define DW9761OFILMAFIOC_G_MOTORMETAINFO _IOR(DW9761OFILMAF_MAGIC,4,stDW9761OFILMAF_MotorMETAInfo)
#endif

#else
#endif

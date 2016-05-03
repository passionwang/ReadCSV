#include "route.h"
#include "lib_record.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<sys/timeb.h>
#include<string.h>
#include<iostream>
using namespace std;
double f_SO2(double u)
{
	double x=u;
	double IAQIp,Cp,BPh,BPl,IAQIh,IAQIl;
	if((x>0)&&(x<=50))
	{
		BPh=50;
		BPl=0;
		IAQIh=50;
		IAQIl=0;
	}
	if((x>50)&&(x<=150))
	{
		BPh=150;
		BPl=50;
		IAQIh=100;
		IAQIl=50;
	}
	if((x>150)&&(x<=475))
	{
		BPh=475;
		BPl=150;
		IAQIh=150;
		IAQIl=100;
	}
	if((x>475)&&(x<=800))
	{
		BPh=800;
		BPl=475;
		IAQIh=200;
		IAQIl=150;
	}
	if((x>800)&&(x<=1600))
	{
		BPh=1600;
		BPl=800;
		IAQIh=300;
		IAQIl=200;
	}
	if((x>1600)&&(x<=2100))
	{
		BPh=2100;
		BPl=1600;
		IAQIh=400;
		IAQIl=300;
	}
	if((x>2120)&&(x<=2620))
	{
		BPh=2620;
		BPl=2120;
		IAQIh=500;
		IAQIl=400;
	}
	Cp=x;
	IAQIp=((IAQIh-IAQIl)/(BPh-BPl))*(Cp-BPl)+IAQIl;
	if(x=0)
		IAQIp=0;
	return IAQIp;
}

double f_NO2(double u)
{
	double x=u;
	double IAQIp,Cp,BPh,BPl,IAQIh,IAQIl;
	if((x>0)&&(x<=40))
	{
		BPh=40;
		BPl=0;
		IAQIh=50;
		IAQIl=0;
	}
	if((x>40)&&(x<=80))
	{
		BPh=80;
		BPl=40;
		IAQIh=100;
		IAQIl=50;
	}
	if((x>80)&&(x<=180))
	{
		BPh=180;
		BPl=80;
		IAQIh=150;
		IAQIl=100;
	}
	if((x>180)&&(x<=280))
	{
		BPh=280;
		BPl=180;
		IAQIh=200;
		IAQIl=150;
	}
	if((x>280)&&(x<=565))
	{
		BPh=565;
		BPl=280;
		IAQIh=300;
		IAQIl=200;
	}
	if((x>565)&&(x<=750))
	{
		BPh=750;
		BPl=565;
		IAQIh=400;
		IAQIl=300;
	}
	if((x>750)&&(x<=940))
	{
		BPh=940;
		BPl=750;
		IAQIh=500;
		IAQIl=400;
	}
	Cp=x;
	IAQIp=((IAQIh-IAQIl)/(BPh-BPl))*(Cp-BPl)+IAQIl;
	if(x=0)
		IAQIp=0;
	return IAQIp;
}

double f_PM10(double u)
{
	double x=u;
	double IAQIp,Cp,BPh,BPl,IAQIh,IAQIl;
	if((x>0)&&(x<=50))
	{
		BPh=50;
		BPl=0;
		IAQIh=50;
		IAQIl=0;
	}
	if((x>50)&&(x<=150))
	{
		BPh=150;
		BPl=50;
		IAQIh=100;
		IAQIl=50;
	}
	if((x>150)&&(x<=250))
	{
		BPh=250;
		BPl=150;
		IAQIh=150;
		IAQIl=100;
	}
	if((x>250)&&(x<=350))
	{
		BPh=350;
		BPl=250;
		IAQIh=200;
		IAQIl=150;
	}
	if((x>350)&&(x<=420))
	{
		BPh=420;
		BPl=350;
		IAQIh=300;
		IAQIl=200;
	}
	if((x>420)&&(x<=500))
	{
		BPh=500;
		BPl=420;
		IAQIh=400;
		IAQIl=300;
	}
	if((x>500)&&(x<=600))
	{
		BPh=600;
		BPl=500;
		IAQIh=500;
		IAQIl=400;
	}
	Cp=x;
	IAQIp=((IAQIh-IAQIl)/(BPh-BPl))*(Cp-BPl)+IAQIl;
	if(x=0)
		IAQIp=0;
	return IAQIp;
}

double f_CO(double u)
{
	double x=u;
	double IAQIp,Cp,BPh,BPl,IAQIh,IAQIl;
	if((x>0)&&(x<=2))
	{
		BPh=2;
		BPl=0;
		IAQIh=50;
		IAQIl=0;
	}
	if((x>2)&&(x<=4))
	{
		BPh=4;
		BPl=2;
		IAQIh=100;
		IAQIl=50;
	}
	if((x>4)&&(x<=14))
	{
		BPh=14;
		BPl=4;
		IAQIh=150;
		IAQIl=100;
	}
	if((x>14)&&(x<=24))
	{
		BPh=24;
		BPl=14;
		IAQIh=200;
		IAQIl=150;
	}
	if((x>24)&&(x<=36))
	{
		BPh=36;
		BPl=24;
		IAQIh=300;
		IAQIl=200;
	}
	if((x>36)&&(x<=48))
	{
		BPh=48;
		BPl=36;
		IAQIh=400;
		IAQIl=300;
	}
	if((x>48)&&(x<=60))
	{
		BPh=60;
		BPl=48;
		IAQIh=500;
		IAQIl=400;
	}
	Cp=x;
	IAQIp=((IAQIh-IAQIl)/(BPh-BPl))*(Cp-BPl)+IAQIl;
	if(x=0)
		IAQIp=0;
	return IAQIp;
}

double f_PM25(double u)
{
	double x=u;
	double IAQIp,Cp,BPh,BPl,IAQIh,IAQIl;
	if((x>0)&&(x<=35))
	{
		BPh=35;
		BPl=0;
		IAQIh=50;
		IAQIl=0;
	}
	if((x>35)&&(x<=75))
	{
		BPh=75;
		BPl=35;
		IAQIh=100;
		IAQIl=50;
	}
	if((x>75)&&(x<=115))
	{
		BPh=115;
		BPl=75;
		IAQIh=150;
		IAQIl=100;
	}
	if((x>115)&&(x<=150))
	{
		BPh=150;
		BPl=115;
		IAQIh=200;
		IAQIl=150;
	}
	if((x>150)&&(x<=250))
	{
		BPh=250;
		BPl=150;
		IAQIh=300;
		IAQIl=200;
	}
	if((x>250)&&(x<=350))
	{
		BPh=350;
		BPl=250;
		IAQIh=400;
		IAQIl=300;
	}
	if((x>350)&&(x<=500))
	{
		BPh=500;
		BPl=350;
		IAQIh=500;
		IAQIl=400;
	}
	Cp=x;
	IAQIp=((IAQIh-IAQIl)/(BPh-BPl))*(Cp-BPl)+IAQIl;
	if(x=0)
		IAQIp=0;
	return IAQIp;
}
//你要完成的功能总入口/////////////////////////////////////////////////////////////////////////////////////////////
void search_route(char *topo[5000], int edge_num)
{
	int* pm25 = (int*)malloc(sizeof(int) * edge_num-1);
	int* pm10 = (int*)malloc(sizeof(int) * edge_num-1);
	double* co = (double*)malloc(sizeof(double) * edge_num-1);
	int* no2 = (int*)malloc(sizeof(int) * edge_num-1);
	int* so2 = (int*)malloc(sizeof(int) * edge_num-1);
	for(int i=1;i<edge_num;i++)
	{
		sscanf(topo[i],"%d,%d,%lf,%d,%d",&pm25[i-1],&pm10[i-1],&co[i-1],&no2[i-1],&so2[i-1]);
	}
	double IAQI[5];
	for(int i=0;i<edge_num-1;i++)
	{
		IAQI[0]=f_SO2(so2[i]);
		IAQI[1]=f_NO2(no2[i]);
		IAQI[2]=f_PM10(pm10[i]);
		IAQI[3]=f_CO(co[i]);
		IAQI[4]=f_PM25(pm25[i]);

		double temp=IAQI[0];
		for(int i=1;i<5;i++)
		{
			if(IAQI[i]>temp)
				temp=IAQI[i];
		}
		record_result(temp);
	}
	free(pm25);
	free(pm10);
	free(co);
	free(no2);
	free(so2);
}

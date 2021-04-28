#pragma once
#include "Policy.h"
#include "cmath"

#define MyCalculation( className, CacheP, VerboseP ) \
				class className : public CacheP, public VerboseP { \
					public: \
					void eval ( double arg ) const { \
						if( !hasCacheFor(arg) ) { \
							double val = sqrt( pow(arg - 7, 2) ); \
							cacheValueForArgument(arg,val); \
							printArgAndResult(arg,val); \
						}\
					}\
				};



						
						


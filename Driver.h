/*
BSD 2-Clause License

Copyright (c) 2018, Marcin Jamroz
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef Driver_h
#define Driver_h

#include "Arduino.h"


class Driver
{
	public:
	Driver(int M1_enable, int M2_enable, int M3_enable, int M4_enable);
	void M1_bind(int A1, int A2);
	void M2_bind(int A3, int A4);
	void M3_bind(int A3, int A4);
	void M4_bind(int A1, int A2);
	
	void up(int speed);
	void down(int speed);
	void left(int speed);
	void right(int speed);
	void stop();
	
	private:
	int _M1_enable, _M2_enable, _M3_enable, _M4_enable;
	int _M1_A1, _M1_A2, _M2_A3, _M2_A4;
	int _M3_A3, _M3_A4, _M4_A1, _M4_A2;
};

#endif

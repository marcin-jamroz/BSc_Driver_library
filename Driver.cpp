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






//#include "Arduino.h"
#include "Driver.h"

Driver::Driver(int M1_enable, int M2_enable, int M3_enable, int M4_enable)
{
	pinMode(M1_enable, OUTPUT);
	pinMode(M2_enable, OUTPUT);
	pinMode(M3_enable, OUTPUT);
	pinMode(M4_enable, OUTPUT);
	
	_M1_enable = M1_enable;
	_M2_enable = M2_enable;
	_M3_enable = M3_enable;
	_M4_enable = M4_enable;
}

void Driver::M1_bind(int A1, int A2)
{
pinMode(A1,OUTPUT);
pinMode(A2, OUTPUT);

_M1_A1 = A1;
_M1_A2 = A2;
	
}

void Driver::M2_bind(int A3, int A4)
{
	pinMode(A3, OUTPUT);
	pinMode(A4, OUTPUT);
	
	_M2_A3 = A3;
	_M2_A4 = A4;
}

void Driver::M3_bind(int A3, int A4)
{
	pinMode(A3, OUTPUT);
	pinMode(A4, OUTPUT);
	
	_M3_A3 = A3;
	_M3_A4 = A4;
}

void Driver::M4_bind(int A1, int A2)
{
	pinMode(A1, OUTPUT);
	pinMode(A2, OUTPUT);
	
	_M4_A1 = A1;
	_M4_A2 = A2;
}

void Driver::up(int speed)
{
	digitalWrite(_M1_enable, HIGH);
	digitalWrite(_M2_enable, HIGH);
	digitalWrite(_M3_enable, HIGH);
	digitalWrite(_M4_enable, HIGH);
	
	digitalWrite(_M1_A2, LOW);
	analogWrite(_M1_A1, speed);

	analogWrite(_M2_A3, speed);
	digitalWrite(_M2_A4, LOW);
	
	analogWrite(_M3_A3, speed);
	digitalWrite(_M3_A4, LOW);

	analogWrite(_M4_A1, speed);
	digitalWrite(_M4_A2, LOW);
}

void Driver::down(int speed)
{
	digitalWrite(_M1_enable, HIGH);
	digitalWrite(_M2_enable, HIGH);
	digitalWrite(_M3_enable, HIGH);
	digitalWrite(_M4_enable, HIGH);
	
	digitalWrite(_M1_A2, HIGH);
	analogWrite(_M1_A1, 255-speed);

	analogWrite(_M2_A3, 255-speed);
	digitalWrite(_M2_A4, HIGH);
	
	analogWrite(_M3_A3, 255-speed);
	digitalWrite(_M3_A4, HIGH);

	analogWrite(_M4_A1, 255-speed);
	digitalWrite(_M4_A2, HIGH);
}

void Driver::left(int speed)
{
	digitalWrite(_M1_enable, HIGH);
	digitalWrite(_M2_enable, HIGH);
	digitalWrite(_M3_enable, HIGH);
	digitalWrite(_M4_enable, HIGH);
	
		digitalWrite(_M1_A2, LOW);
	analogWrite(_M1_A1, speed);

	analogWrite(_M2_A3, speed);
	digitalWrite(_M2_A4, LOW);
	
	analogWrite(_M3_A3, 255-speed);
	digitalWrite(_M3_A4, HIGH);

	analogWrite(_M4_A1, 255-speed);
	digitalWrite(_M4_A2, HIGH);
}

void Driver::right(int speed)
{
	digitalWrite(_M1_enable, HIGH);
	digitalWrite(_M2_enable, HIGH);
	digitalWrite(_M3_enable, HIGH);
	digitalWrite(_M4_enable, HIGH);
	
	digitalWrite(_M1_A2, HIGH);
	analogWrite(_M1_A1, 255-speed);

	analogWrite(_M2_A3, 255-speed);
	digitalWrite(_M2_A4, HIGH);
	
	analogWrite(_M3_A3, speed);
	digitalWrite(_M3_A4, LOW);

	analogWrite(_M4_A1, speed);
	digitalWrite(_M4_A2, LOW);
}
void Driver::stop()
{
	
	
	digitalWrite(_M1_A1, LOW);
	digitalWrite(_M1_A2, LOW);
	digitalWrite(_M2_A3, LOW);
	digitalWrite(_M2_A4, LOW);
	digitalWrite(_M3_A3, LOW);
	digitalWrite(_M3_A4, LOW);
	digitalWrite(_M4_A1, LOW);
	digitalWrite(_M4_A2, LOW);
	
	digitalWrite(_M1_enable, LOW);
	digitalWrite(_M2_enable, LOW);
	digitalWrite(_M3_enable, LOW);
	digitalWrite(_M4_enable, LOW);
}

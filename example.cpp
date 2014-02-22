/*
Copyright (c) 2014 Bernd Klein

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

// define pin D7 as led, no wiring needed!
int led = D7; 

// define a variable we can check
int someVariable = 42;

// function to switch our LED on/off, depending on the user input
int switchLED(String command)
{
    if (command == "on"){
        // LED goes on
        digitalWrite(led,HIGH);
        return 1;
    }
    if (command == "off"){
        // LED goes off
        digitalWrite(led,LOW);
        return 1;
    }
    else {
        // ups!
        return -1;
    }
}
// setting things up
void setup() 
{
    // initialize D7 pin as an output
    pinMode(led, OUTPUT);
    
    // initalize a function we can access via the Spark Cloud
    Spark.function("switchLED", switchLED);
    
    // initalize a variable we can acces via the Spark Cloud
    Spark.variable("someVariable", &someVariable, INT);
}

// This routine loops forever 
void loop() 
{

}
/*
 *
 */

#ifndef __MINI_TIMER_1_H__
#define __MINI_TIMER_1_H__

#include "Arduino.h"

/*
 * This class represents an interface from which to manage the Timer 1 of an ATmega328P processor on a Arduino Uno. It
 * can be use to manage it as a timer in the strict sense of the word, with functionalities for starting, stopping
 * and resetting it. Moreover, it can perform an action when the specified period of time has elapsed. It can count
 * up to four seconds, more or less, because of the size of the ATmega328P's registers. Every value greater than
 * that will be subsituted by the maximum value allowed into the counter register.
 */
class MiniTimerOne {
    public:
        /*
         * Returns a pointer to the only instance of this class.
         */
        static MiniTimerOne *getInstance();
        /* 
         * Initializes the timer so as to use the CTC (Clear Timer on Compare match) timer mode, stop the timer from
         * counting CPU clock cycles and reset its counter to zero.
         */
        void init(void);
        /*
         * Sets the period of the timer after which it puts its counter to zero and an interrupt is called. The 
         * default value is zero, which doesn't make the timer start, but stops it.
         */
        void setPeriod(unsigned long int period);
        /* 
         * Sets the function called when the interrupt is fired and enables the firing of interrupts for the timer.
         * The default value is a pointer to a routine which does nothing.
         */
        void attachInterrupt(void (*isr)(void));
        /* 
         * Disables the firing of interrupts.
         */
        void detachInterrupt(void);
        /* 
         * Starts the timer.
         */
        void start(void);
        /* 
         * Stops the timer from counting, it doesn't reset the value of the counter.
         */
        void stop(void);
        /*
         * Sets the timer counter to zero. It doesn't stop the timer from counting.
         */
        void reset(void);
        /*
         * Returns the callback routine currently called when the interrupt is fired.
         */
        void (*getCallback(void))(void);
    private:
        static MiniTimerOne *SINGLETON;

        MiniTimerOne(void);

        void (*_isrCallback)(void);
        char _clockSelectBits;
};

/*
 * Global variable accessible from the end user for facilitating the use of this timer library.
 */
extern MiniTimerOne MiniTimer1;

#endif

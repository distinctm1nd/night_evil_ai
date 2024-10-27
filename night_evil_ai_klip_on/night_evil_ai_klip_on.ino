#include <avr/io.h>
#include <util/delay.h>

#define EYE_LED_ARRAY 1      
#define NUM_EYE_LEDS 2         
#define LETTER_LED_ARRAY 2    
#define NUM_LETTER_LEDS 7        
#define BUTTON_PIN 3         

enum LedMode {
    NIGHT_OF_THE_LIVING_DEAD, 
    NIGHT_OF_THE_RED_MOON,   
    NIGHT_OF_THE_WINTER_MOON,  
    NIGHT_OF_THE_SALAMANDER,    
    NIGHT_OF_THE_FROZEN_MOON,   
    NIGHT_OF_THE_KILLER_MOON,
    NIGHT_OF_THE_EVIL_KLIPPY_AI,
    NIGHT_OF_THE_KILLER_CLOWNS, 
    NIGHT_OF_THE_HACKERS,
    NIGHT_OF_DISCORD
};

LedMode currentMode = NIGHT_OF_THE_HACKERS; // Set default mode

void nightOfTheLivingDeadLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Light Red
            g = 0; 
            r = 200;
            b = 0; 
            break;
        case 1: // Bright Red
            g = 0; 
            r = 255;
            b = 0; 
            break;
        case 2: // Light Brown
            g = 165;
            r = 90; 
            b = 0; 
            break;
        case 3: // Dark Brown
            g = 75; 
            r = 40; 
            b = 0; 
            break;
        case 4: // Yellow
            g = 255; 
            r = 255; 
            b = 0; 
            break;
    }
}


void nightOfTheRedMoonLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Light Red
            g = 0;
            r = 200;                        
            b = 0;             
            break;
        case 1: // Medium Red
            g = 0;
            r = 255;                        
            b = 0;             
            break;
        case 2: // Dark Red
            g = 0;
            r = 150;                        
            b = 0;             
            break;
        case 3: // Deep Red
            g = 0;
            r = 100;                        
            b = 0;             
            break;
        case 4: // Yellow
            g = 255; 
            r = 255;                     
            b = 0;             
            break;
    }
}


void nightOfTheWinterMoonLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Light Purple
            g = 128;
            r = 0;    
            b = 255;          
            break;
        case 1: // Dark Purple
            g = 75;
            r = 0;    
            b = 150;          
            break;
        case 2: // Light Blue
            g = 0;
            r = 0;    
            b = 200;          
            break;
        case 3: // Dark Blue
            g = 0;
            r = 0;    
            b = 100;          
            break;
        case 4: // Red
            g = 0;
            r = 255;    
            b = 0;            
            break;
    }
}


void nightOfTheSalamanderLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Light Green
            g = 200; 
            r = 0;  
            b = 0;   
            break;
        case 1: // Medium Light Green
            g = 150; 
            r = 0;   
            b = 0;  
            break;
        case 2: // Medium Green
            g = 100; 
            r = 0;   
            b = 0;   
            break;
        case 3: // Dark Green
            g = 50; 
            r = 0;   
            b = 0;   
            break;
        case 4: // Yellow-Green
            g = 255; 
            r = 255;
            b = 0;  
            break;
    }
}


void nightOfTheFrozenMoonLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Light Purple
            g = 128; 
            r = 64;  
            b = 128; 
            break;
        case 1: // Dark Purple
            g = 0;   
            r = 0;  
            b = 255;
            break;
        case 2: // Light Blue
            g = 0;   
            r = 0;   
            b = 200;
            break;
        case 3: // Dark Blue
            g = 0;  
            r = 0;  
            b = 100; 
            break;
        case 4: // White
            g = 255; 
            r = 255; 
            b = 255;
            break;
    }
}


void nightOfTheKillerMoonLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Bright Red
            g = 0; 
            r = 255; 
            b = 0; 
            break;
        case 1: // Medium Red
            g = 0; 
            r = 200;
            b = 0; 
            break;
        case 2: // Dark Red
            g = 0; 
            r = 150; 
            b = 0; 
            break;
        case 3: // Deeper Red
            g = 0; 
            r = 100; 
            b = 0; 
            break;
        case 4: // Dark Brown
            g = 10;  
            r = 40;  
            b = 0;   
            break;
    }
}


void nightOfTheEvilKlippyAiLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 4) {
        case 0: // Light Orange
            g = 165; 
            r = 255; 
            b = 0; 
            break;  
        case 1: // Medium Orange
            g = 140; 
            r = 255; 
            b = 0; break;  
        case 2: // Dark Orange
            g = 100; 
            r = 200; 
            b = 0; break;  
        case 3: // White
            g = 255; 
            r = 255; 
            b = 255; 
            break; 
    }
}

void nightOfTheKillerClownsLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Red
            g = 0; 
            r = 255; 
            b = 0; 
            break;
        case 1: // Yellow
            g = 255; 
            r = 255; 
            b = 0; 
            break;
        case 2: // Orange
            g = 165; 
            r = 255; 
            b = 0; 
            break;
        case 3: // Green
            g = 0; 
            r = 255; 
            b = 0; 
            break;
        case 4: // Purple
            g = 128; 
            r = 0; 
            b = 128; 
            break;
    }
}

void nightOfTheHackersLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Red
            g = 0; 
            r = 255; 
            b = 0; 
            break;
        case 1: // Green
            g = 255; 
            r = 0; 
            b = 0; 
            break;
        case 2: // Blue
            g = 0; 
            r = 0; 
            b = 255; 
            break;
        case 3: // Orange
            g = 165; 
            r = 255; 
            b = 0; 
            break;
        case 4: // Purple
            g = 128; 
            r = 0; 
            b = 128; 
            break;
    }
}

void nightOfDiscordLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Light Blue
            g = 0; 
            r = 0; 
            b = 255; 
            break;
        case 1: // Medium Blue
            g = 0; 
            r = 0; 
            b = 200; 
            break;
        case 2: // Dark Blue
            g = 0; 
            r = 0; 
            b = 100; 
            break;
        case 3: // Deep Blue
            g = 0; 
            r = 0; 
            b = 50;  
            break;
        case 4: // White
            g = 255; 
            r = 255; 
            b = 255; 
            break;
    }
}


void sendColor(uint8_t g, uint8_t r, uint8_t b, uint8_t ledPin) {
    sendByte(g, ledPin);
    sendByte(r, ledPin);
    sendByte(b, ledPin);
}

void sendByte(uint8_t byte, uint8_t ledPin) {
    for (int i = 0; i < 8; i++) {
        if (byte & (1 << (7 - i))) {
            PORTA.OUTSET = (1 << ledPin);
            _delay_us(0.4); // Adjusted timing
            PORTA.OUTCLR = (1 << ledPin);
            _delay_us(0.85); // Adjusted timing for LOW
        } else {
            PORTA.OUTSET = (1 << ledPin);
            _delay_us(0.2); // Adjusted timing for HIGH
            PORTA.OUTCLR = (1 << ledPin);
            _delay_us(0.9); // Adjusted timing for LOW
        }
    }
}

void colorWipe(uint8_t green, uint8_t red, uint8_t blue, uint8_t ledPin, uint8_t numLeds) {
    for (int i = 0; i < numLeds; i++) {
        sendColor(green, red, blue, ledPin); 
        _delay_us(500); 
    }
}

void setup() {
    // Set eye_led_array and letter_led_array as output
    PORTA.DIRSET = (1 << EYE_LED_ARRAY) | (1 << LETTER_LED_ARRAY);
    
    PORTA.DIRCLR = (1 << BUTTON_PIN);
    PORTA.OUTSET = (1 << BUTTON_PIN); 
    
    // Ensure all LEDs are off at the start
    colorWipe(0, 0, 0, EYE_LED_ARRAY, NUM_EYE_LEDS);
    colorWipe(0, 0, 0, LETTER_LED_ARRAY, NUM_LETTER_LEDS);
    _delay_ms(100); 
}

bool isButtonPressed() {
    return (PORTA.IN & (1 << BUTTON_PIN)) == 0;
}


void loop() {
    static uint8_t ledIndex = 0; 
    static uint32_t lastUpdateTime = 0;
    const uint32_t updateInterval = 175; 
    
    if (millis() - lastUpdateTime >= updateInterval) {
        lastUpdateTime = millis();

        uint8_t green, red, blue;

        // Update the color for the current LED based on the mode
        switch (currentMode) {
            case NIGHT_OF_THE_LIVING_DEAD:
                nightOfTheLivingDeadLedMode(ledIndex, green, red, blue);
                break;
            case NIGHT_OF_THE_RED_MOON:
                nightOfTheRedMoonLedMode(ledIndex, green, red, blue);
                break;
            case NIGHT_OF_THE_WINTER_MOON:
                nightOfTheWinterMoonLedMode(ledIndex, green, red, blue);
                break;
            case NIGHT_OF_THE_SALAMANDER:
                nightOfTheSalamanderLedMode(ledIndex, green, red, blue);
                break;
            case NIGHT_OF_THE_FROZEN_MOON:
                nightOfTheFrozenMoonLedMode(ledIndex, green, red, blue);
                break;
            case NIGHT_OF_THE_KILLER_MOON:
                nightOfTheKillerMoonLedMode(ledIndex, green, red, blue);
                break;
            case NIGHT_OF_THE_EVIL_KLIPPY_AI: 
                nightOfTheEvilKlippyAiLedMode(ledIndex, green, red, blue);
                break;
            case NIGHT_OF_THE_KILLER_CLOWNS: 
                nightOfTheKillerClownsLedMode(ledIndex, green, red, blue);
                break;
            case NIGHT_OF_THE_HACKERS:
                nightOfTheHackersLedMode(ledIndex, green, red, blue);
                break;
            case NIGHT_OF_DISCORD: 
                nightOfDiscordLedMode(ledIndex, green, red, blue);
                break;
        }

        // Light up the current LED
        sendColor(green, red, blue, LETTER_LED_ARRAY); 
        _delay_us(500); 

        // Update eye LEDs to match the current LED color
        for (uint8_t i = 0; i < NUM_EYE_LEDS; i++) {
            sendColor(green, red, blue, EYE_LED_ARRAY); 
        }

        // Update all previous LEDs to maintain their color
        for (uint8_t i = 0; i < NUM_LETTER_LEDS; i++) {
            uint8_t prevGreen, prevRed, prevBlue;
            switch (currentMode) {
                case NIGHT_OF_THE_LIVING_DEAD:
                    nightOfTheLivingDeadLedMode(((i + ledIndex) * 256 / NUM_LETTER_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case NIGHT_OF_THE_RED_MOON:
                    nightOfTheRedMoonLedMode(((i + ledIndex) * 256 / NUM_LETTER_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case NIGHT_OF_THE_WINTER_MOON:
                    nightOfTheWinterMoonLedMode(((i + ledIndex) * 256 / NUM_LETTER_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case NIGHT_OF_THE_SALAMANDER:
                    nightOfTheSalamanderLedMode(((i + ledIndex) * 256 / NUM_LETTER_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case NIGHT_OF_THE_FROZEN_MOON:
                    nightOfTheFrozenMoonLedMode(((i + ledIndex) * 256 / NUM_LETTER_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case NIGHT_OF_THE_KILLER_MOON:
                    nightOfTheKillerMoonLedMode(((i + ledIndex) * 256 / NUM_LETTER_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case NIGHT_OF_THE_EVIL_KLIPPY_AI: 
                    nightOfTheEvilKlippyAiLedMode(((i + ledIndex) * 256 / NUM_LETTER_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case NIGHT_OF_THE_KILLER_CLOWNS: 
                    nightOfTheKillerClownsLedMode(((i + ledIndex) * 256 / NUM_LETTER_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case NIGHT_OF_THE_HACKERS: 
                    nightOfTheHackersLedMode(((i + ledIndex) * 256 / NUM_LETTER_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case NIGHT_OF_DISCORD: 
                    nightOfDiscordLedMode(((i + ledIndex) * 256 / NUM_LETTER_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
            }
            sendColor(prevGreen, prevRed, prevBlue, LETTER_LED_ARRAY); 
        }

        // Update LED index for the next iteration
        ledIndex = (ledIndex + 1) % NUM_LETTER_LEDS;
    }

    // Button logic for mode change
    if (isButtonPressed()) {
        currentMode = static_cast<LedMode>((currentMode + 1) % 10); 
        _delay_ms(300); 
    }

}

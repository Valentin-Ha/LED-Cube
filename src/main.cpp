#include <Arduino.h>

// Define pin numbers for the LEDs and transistors
#define pin1 11
#define pin2 12
#define pin3 4
#define pin4 5
#define pin5 6  // Middle LED
#define pin6 7
#define pin7 8
#define pin8 9
#define pin9 10
#define TrPin1 18
#define TrPin2 19
#define TrPin3 20

#define DELAY 1            // Time delay for refreshing the layers
#define IMG_DELAY 50      // How long each image is shown
#define IMG_COUNT 26      // Total number of images

// Define images as 3D arrays (3 layers of 3x3 grid)
int img1[3][3][3] = {
  {
    {1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {1, 0, 1},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}
  }
};

int img2[3][3][3] = {
  {
    {0, 0, 0},
    {1, 1, 1},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {1, 0, 1},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {1, 1, 1},
    {0, 0, 0}
  }
};

int img3[3][3][3] = {
  {
    {0, 0, 0},
    {0, 0, 0},
    {1, 1, 1}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {1, 0, 1}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {1, 1, 1}
  }
};

int img4[3][3][3] = {
  {
    {0, 0, 0},
    {1, 1, 1},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {1, 0, 1},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {1, 1, 1},
    {0, 0, 0}
  }
};

int img5[3][3][3] = {
  {
    {1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {1, 0, 1},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}
  }
};

int img6[3][3][3] = {
  {
    {0, 0, 0},
    {1, 1, 1},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {1, 0, 1},
    {0, 0, 0}
  },
  {
    {1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}
  }
};

int img7[3][3][3] = {
  {
    {0, 0, 0},
    {0, 0, 0},
    {1, 1, 1}
  },
  {
    {0, 0, 0},
    {1, 0, 1},
    {0, 0, 0}
  },
  {
    {1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}
  }
};

int img8[3][3][3] = {
  {
    {0, 0, 0},
    {0, 0, 0},
    {1, 1, 1}
  },
  {
    {1, 1, 1},
    {1, 0, 1},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  }
};

int img9[3][3][3] = {
  {
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  }
};

int img10[3][3][3] = {
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  }
};

int img11[3][3][3] = {
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
  }
};


int img12[3][3][3] = {
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {1, 1, 0},
    {1, 0, 0},
    {1, 1, 0}
  },
  {
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1}
  }
};

int img13[3][3][3] = {
  {
    {1, 0, 0},
    {1, 0, 0},
    {1, 0, 0}
  },
  {
    {0, 1, 0},
    {0, 0, 0},
    {0, 1, 0}
  },
  {
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1}
  }
};

int img14[3][3][3] = {
  {
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0}
  },
  {
    {0, 1, 0},
    {0, 0, 0},
    {0, 1, 0}
  },
  {
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1}
  }
};

int img15[3][3][3] = {
  {
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1}
  },
  {
    {0, 0, 1},
    {0, 0, 0},
    {0, 0, 1}
  },
  {
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1}
  }
};

int img16[3][3][3] = {
  {
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0}
  },
  {
    {0, 1, 0},
    {0, 0, 0},
    {0, 1, 0}
  },
  {
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0}
  }
};

int img17[3][3][3] = {
  {
    {1, 0, 0},
    {1, 0, 0},
    {1, 0, 0}
  },
  {
    {1, 0, 0},
    {0, 0, 0},
    {1, 0, 0}
  },
  {
    {1, 0, 0},
    {1, 0, 0},
    {1, 0, 0}
  }
};

int img18[3][3][3] = {
  {
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0}
  },
  {
    {0, 1, 0},
    {0, 0, 0},
    {0, 1, 0}
  },
  {
    {1, 0, 0},
    {1, 0, 0},
    {1, 0, 0}
  }
};

int img19[3][3][3] = {
  {
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1}
  },
  {
    {0, 1, 0},
    {0, 0, 0},
    {0, 1, 0}
  },
  {
    {1, 0, 0},
    {1, 0, 0},
    {1, 0, 0}
  }
};

int img20[3][3][3] = {
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {0, 1, 1},
    {0, 0, 1},
    {0, 1, 1}
  },
  {
    {1, 0, 0},
    {1, 0, 0},
    {1, 0, 0}
  }
};

int img21[3][3][3] = {
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
  }
};

int img22[3][3][3] = {
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  }
};

int img23[3][3][3] = {
  {
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  }
};

int img24[3][3][3] = {
  {
    {1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {1, 0, 1},
    {1, 1, 1}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  }
};

int img25[3][3][3] = {
  {
    {1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {1, 0, 1},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {0, 0, 0},
    {1, 1, 1}
  }
};

int img26[3][3][3] = {
  {
    {1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {1, 0, 1},
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {1, 1, 1},
    {0, 0, 0}
  }
};



// Function to display a given image
void displayImage(int image[3][3][3]) {
  // Loop through each layer (3 layers total)
  for (int z = 0; z < 3; z++) {
    // Turn off all transistors
    digitalWrite(TrPin1, LOW);
    digitalWrite(TrPin2, LOW);
    digitalWrite(TrPin3, LOW);

    // Turn on the transistor for the current layer
    if (z == 0) digitalWrite(TrPin1, HIGH);
    if (z == 1) digitalWrite(TrPin2, HIGH);
    if (z == 2) digitalWrite(TrPin3, HIGH);

    // Set the state of each LED according to the image data
    digitalWrite(pin1, image[z][2][0]);  // Set LED 1 based on image data
    digitalWrite(pin2, image[z][1][0]);  // Set LED 2 based on image data
    digitalWrite(pin3, image[z][0][0]);  // Set LED 3 based on image data
    digitalWrite(pin4, image[z][2][1]);  // Set LED 4 based on image data
    digitalWrite(pin5, image[z][1][1]);  // Set LED 5 based on image data (middle LED)
    digitalWrite(pin6, image[z][0][1]);  // Set LED 6 based on image data
    digitalWrite(pin7, image[z][2][2]);  // Set LED 7 based on image data
    digitalWrite(pin8, image[z][1][2]);  // Set LED 8 based on image data
    digitalWrite(pin9, image[z][0][2]);  // Set LED 9 based on image data

    delay(DELAY);  //Speed on wich the layers are refreshed
  }
}

void setup() {
  // Set all pins as outputs
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(TrPin1, OUTPUT);
  pinMode(TrPin2, OUTPUT);
  pinMode(TrPin3, OUTPUT);
}

void loop() {
  // Array of image pointers
  int (*images[IMG_COUNT])[3][3][3] = {&img1, &img2, &img3, &img4, &img5, &img6, &img7, &img8, &img9, &img10, &img11, &img12, &img13, &img14, &img15, &img16, &img17, &img18, &img19, &img20, &img21, &img22, &img23, &img24, &img25, &img26};

  // Loop through each image and display it
  for (int j = 0; j < IMG_COUNT; j++) {
    // Show each image multiple times
    for (int i = 0; i < IMG_DELAY; i++) {
      displayImage(*images[j]);  // Display the current image
    }
  }
}

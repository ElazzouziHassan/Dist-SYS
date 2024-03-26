struct number {
  float x;
};

program SQRT_PROG {
  version SQRT_VERS {
    float SQRT(number) = 1 ;
  } = 1;
} = 0x20000002;

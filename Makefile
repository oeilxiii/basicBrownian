basicBrownian:	basicBrownian.cpp
	g++ basicBrownian.cpp `sdl-config --cflags --libs`  -o basicBrownian

clean:
	rm basicBrownian

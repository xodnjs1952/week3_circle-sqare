#include <GLFW/glfw3.h>
#include<algorithm>
const int width = 640; 
const int height = 640; 

 
 float* pixels = new float[width*height * 3]; 

  void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue) 
 { 
 	pixels[(i + width* j) * 3 + 0] = red; 
 	pixels[(i + width* j) * 3 + 1] = green; 
 	pixels[(i + width* j) * 3 + 2] = blue; 
 } 

  void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) 
 { 
 	for (int i = i0; i <= i1; i++) 
	{ 
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0; 
 
		drawPixel(i, j, red, green, blue); 
	} 
  } 



int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
	
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
	
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

		std::fill_n(pixels, width*height * 3, 1.0f);	// background 
		 
		//line
		for(int i=20;i<30;i++){
		 drawLine(i,400-i, 200+i, 500-i, 1.0f,0.0f, 0.0f); 
		}
		for(int i=20;i<30;i++){
		 drawLine(i+1,400-i+1, 200+i+1, 500-i+1, 1.0f,0.0f, 0.0f); 
		}


		//emty square
		for(int i=400;i<500;i++){//채워진 네모
			for(int j=250;j<350;j++){
				drawPixel(j, i, 1.0f,0.0f, 0.0f);}}
		for(int i=410;i<490;i++){//빈공간
			for(int j=260;j<340;j++){
				drawPixel(j, i, 1.0f,1.0f, 1.0f);}}
		
		
		
		
		//full square
		for(int i=400;i<500;i++){
			for(int j=450;j<550;j++){
				drawPixel(j, i, 1.0f,0.0f, 0.0f);}}


		 //triangle
		 drawLine(50, 100, 100, 200, 1.0f,0.0f, 0.0f); 
		for(int j=50;j<170;j++){
				drawPixel(j, 100, 1.0f,0.0f, 0.0f);} 
		 drawLine(100, 200, 170, 100, 1.0f,0.0f, 0.0f);

		//empty circle 중심이 150,350 반지름이 50짜리
		for(int i=100;i<200;i++){
			for(int j=250;j<350;j++){

				double circle;
				circle= ((double)i-150)*((double)i-150)+((double)j-300)*((double)j-300)-50*50;
				if(circle<0.0){drawPixel(j, i, 1.0f,0.0f, 0.0f);}
				else {}
			}}
		//empty spcace make
		for(int i=100;i<200;i++){
			for(int j=250;j<350;j++){

				double circle;
				circle= ((double)i-150)*((double)i-150)+((double)j-300)*((double)j-300)-40*40;
				if(circle<0.0){drawPixel(j, i, 1.0f,1.0f, 1.0f);}
				else {}
			}}


		//full circle 중심이 150,400 반지름이 50짜리
		for(int i=100;i<200;i++){
			for(int j=450;j<550;j++){

				double circle;
				circle= ((double)i-150)*((double)i-150)+((double)j-500)*((double)j-500)-50*50;
				if(circle<0.0){drawPixel(j, i, 1.0f,0.0f, 0.0f);}
				else {}
			}}







		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
	
    glfwTerminate();
	
    return 0;
	
}

#include <stdio.h>

struct Person{
	 char* realName;
	 char* placeToLive;
	 float height;
};

int main(int argc, char const *argv[])
{
	struct Person Batman;
	Batman.realName = "Bruce Wayne";
	Batman.placeToLive = "Gotham";
	Batman.height = 6.7;

	printf("The person is %s , living in the city %s and he is %.1f feet tall.\n",Batman.realName,Batman.placeToLive,Batman.height);

	return 0;
}
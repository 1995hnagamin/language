int mc91(int n) {
	if (n > 100) {
		return n - 10;
	}
	return mc91(mc91(n + 11));
}

int main(void) {
	int i;
	switch (99) {
		case 0 ... 99:
			break;
		case 100:
			break;
		default:
			break;
	}
	return i;
}

case $VAR in
	1) NAME="ONE" ;;
	2) NAME="TWO" ;;
	3) NAME="THREE" ;;
	*) NAME="MANY" ;;
esac

echo "${VAR}=${NAME}"

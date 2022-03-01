int=1
while(( $int<=100 ))
do
echo "请输入成绩（0~100）"
read line

if [ $line -ge 0 ] && [ $line -lt 60 ]
then
	echo "E"
elif [ $line -ge 60 ] && [ $line -lt 70 ]
then
	echo "D"
elif [ $line -ge 70 ] && [ $line -lt 80 ]
then
	echo "C"
elif [ $line -ge 80 ] && [ $line -lt 90 ]
then 
	echo "B"
elif [ $line -ge 90 ] && [ $line -le 100]
then
	echo "A"
else 
	echo "输入成绩错误"
fi
done
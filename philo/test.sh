# echo "testing ./philo 5 800 200 200 5"
# for i in {1..5}
# do
#   ./philo 5 800 200 200 & sleep 5 && kill $!
# done

echo "testing ./philo 5 80 20 20 5"
for i in {1..100}
do
    ./philo 3 410 200 200 5 | grep "is eating" | wc -l
done

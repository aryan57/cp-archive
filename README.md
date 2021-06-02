steps to set up a cron job can be found at https://www.cyberciti.biz/faq/how-do-i-add-jobs-to-cron-under-linux-or-unix-oses/

or,
- $ `crontab -e`
- append `*/15 * * * * /home/aryan/.cp-archive/script.sh >/dev/null 2>&1` for running the script every 15 minutes

make sure to give the permission to execute for the script
![Screenshot from 2021-06-02 18-09-48](https://user-images.githubusercontent.com/55305876/120481540-d4277600-c3cd-11eb-87c1-8e7a78b4db95.png)

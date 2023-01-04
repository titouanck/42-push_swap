SRCS = ${wildcard srcs/*.c}

OBJS = ${SRCS:.c=.o}

INC = -I inc/ -I libft
LIBFTPATH = -L libft -lft
LIBS = ${INC} ${LIBFTPATH}

# 3
# NUMBERS = 4588272 2483383 5448761
# 5
# NUMBERS = 18 54 89 76 3
# NUMBERS = 1859216 5446855 8995295 7629304 350550
# 100
# NUMBERS = 8649 5692 6993 6183 8570 8401 6446 2714 1622 3285 750 9565 4680 8468 6618 2174 2257 8078 1398 6171 4466 396 3907 6656 3679 3905 5329 9585 3055 1917 16 9055 5445 3671 8276 8635 8016 5837 3068 976 6363 8146 8333 273 1653 24 9182 7682 7719 4562 8888 4174 5521 7938 6093 5151 4298 9400 7813 4225 3704 6754 5628 5687 9296 7361 7797 2208 1932 4930 3976 7183 1997 7438 3422 9544 1559 2168 1219 4434 9900 9799 5298 8244 6330 7704 9924 9543 1477 4979 7760 3983 3287 1995 1611 1187 1095 2393 4065 7070
# 500
# NUMBERS = 2758 4018 3897 7088 2955 8742 1418 4779 735 8685 9844 8335 8363 1093 416 3752 1411 8019 7512 9220 5046 5785 4790 6171 9912 6548 6945 4005 4871 5239 7959 6687 3232 4960 3378 2330 7161 1970 8960 4677 402 2482 7010 4586 9999 1699 4269 7545 43 3278 6769 2537 7381 2633 9266 4916 7114 7246 1551 4325 1472 2289 2567 5802 9972 3470 8638 2748 2360 5142 1750 7149 4304 3201 577 8361 5240 2953 4746 4261 2388 368 2962 8941 7339 8946 3022 2627 7891 9934 7317 6582 7574 1179 6192 6358 2416 2206 7553 6257 4349 2385 8109 8873 5667 9840 2241 7475 6534 6203 9634 835 4203 3177 3967 3416 6452 5947 5965 5453 4421 6431 4895 9762 104 519 696 298 4806 1189 249 8427 1741 707 867 7716 3484 9109 3567 1717 4323 2878 9436 2361 4122 6355 4803 2210 81 1327 1159 5411 343 7092 4694 5834 8628 8932 9474 721 9338 5021 8355 8354 2506 1691 4873 2661 1900 994 3256 5655 7265 3298 7792 914 9267 9129 1582 4687 8542 92 655 2569 1600 9364 1809 4642 5128 3887 2014 3381 880 2833 8897 3842 8104 9569 2133 4039 3986 6193 5912 7753 4781 5380 1546 7303 3625 2322 2478 8121 7422 9332 3755 7047 9779 6602 9968 8147 1387 5073 5706 6045 6285 1599 563 7616 6425 6440 1427 2270 9985 4116 4951 4516 7410 6183 1868 1054 7879 4200 2305 1141 8924 5332 7706 1409 5865 7236 1928 647 6414 7404 395 8799 5550 9122 9072 427 8320 5524 9580 310 5421 4346 1359 3023 1624 2737 1447 1605 4084 7878 4876 9494 668 7531 5352 9967 7868 2971 2141 8097 8963 6572 5918 3979 342 5992 9979 5126 4666 4274 1475 5472 5987 3057 3975 9564 1945 4671 2677 9885 4944 7940 5526 1849 3103 8690 7056 4395 3049 6030 1706 9095 6421 4437 9215 8223 706 4027 4448 8240 2950 4332 8017 2027 526 4356 8307 7494 68 6843 219 178 6995 9426 5413 7738 2079 3 9617 1893 2299 7765 6077 8018 7477 3681 4541 810 7176 2273 931 8248 2424 5765 5269 2057 4133 3467 8641 3212 9022 9244 438 3644 78 8042 1793 8872 9331 6693 4766 3742 4592 4750 4676 504 2596 5204 4901 6215 6157 3281 9490 2894 9230 3408 6802 3155 2876 676 5799 5829 4863 3025 19 5709 2946 8035 7374 8522 5796 7132 9770 6547 6675 2812 1594 8828 2601 480 224 4486 5619 8745 344 5156 1613 4229 385 89 3462 6194 3134 7964 6003 4186 9986 3204 9597 5556 1812 7894 1735 1115 7369 2526 8041 267 6617 8074 6694 7319 8128 3277 5277 6972 183 6780 1825 190 9990 4260 7903 2855 6688 989 6405 4415 7493 1739 7602 7058 7084 5715 5986 113 6954 1041 9383 5385 3800 181 1060 9128 2768 3207 1233 2068 4414 6468 2142 8450 1585 7215 2125 2325 2734 6525 7936 9123 7697 6669 6823 3590 1616 5015
# 1000
# NUMBERS = 3820704 2269740 6889032 8452646 1265570 5077586 8103873 1377349 1515860 5432868 6097901 6642152 5609843 6304432 6788119 7237543 6960346 48713 6084216 3271801 7784548 7701772 3943080 2946826 481291 7287736 4369603 4937332 2739072 4044872 2236377 5010627 9334798 1613438 8201234 6773697 4282421 2971608 8457257 1916210 3439607 3698342 9413916 982324 9250834 1737108 882732 8310616 290508 7626640 7904656 5200252 9590802 2590102 4666634 6347338 5649081 690226 4055191 7863786 8836760 3098117 728069 134844 3408485 3656843 5841076 8788339 7416460 7988091 3828764 6781547 2731892 6938353 9310747 6578193 2054255 8273069 9875149 4170553 780564 855192 6487708 8587339 1549814 5643765 377716 6783804 3570173 1286029 2828090 6624657 9436002 7833702 1747907 9108742 3074991 1172524 9869049 495367 9360240 6169424 7800478 3453007 7308079 8497036 9916128 4568063 1471 8251842 4536354 2156151 1611999 4294591 1980422 3332282 2324671 3764800 6904864 4600 6084689 8305661 2485457 4770687 803716 9611955 9930665 571571 9383795 653386 3359743 5053254 6083227 575934 4121485 8300173 3879350 4554085 3159133 3208942 4401454 2782367 275122 8177374 1091760 9810020 8889687 9859730 564063 6980455 7726156 3009530 7276602 5749056 4606184 698469 8774305 82240 883799 439166 2062402 8434650 5688855 4230461 1563101 2166999 9002240 3376718 8801777 2652176 6921498 9379293 4086346 2851516 3899118 1620650 1745978 2688348 6673232 5092159 9811502 6069881 3522780 594879 19408 3519253 323051 7803679 7574834 9237130 661633 1373559 8363339 9072538 3481417 4730586 9511818 1579454 668855 3661386 8469804 3068395 8275673 9371416 5484409 7311345 7874105 7109766 4442184 2362418 1142353 8586675 6989469 8932590 6191405 462924 1918390 8421306 4121479 4924829 4445193 991436 2435031 9615672 5956166 944319 1781493 5302640 1653178 6726707 7829241 4326357 7028812 2344321 7945783 2982333 9684143 7052993 2862766 7082736 466609 7917900 7326799 2178558 5149075 3910263 8675330 3399727 8052744 3187652 1545784 7587190 9886332 4281534 2087064 5806187 2785915 7640976 9970077 4832867 2054769 7111346 691873 1083104 5749650 6159758 5566205 7892615 7093914 7751381 3105826 7623830 2541863 2525207 6401343 7366851 3745729 5635870 3549547 2568745 4238316 2328693 6139068 4279607 166481 5350017 4867568 7566530 659629 7935701 16821 7053150 2220979 8968054 7757847 9275530 6655776 3928119 5906511 6086871 7906139 6249156 6658092 1311326 144214 453219 681444 6922294 9853712 8941194 2442717 4501904 1224301 3394557 7202329 107422 959499 7890681 9420770 1642723 8365871 8966179 716669 2861349 5676111 3708680 4139159 4546049 4843289 4608709 2032840 246266 7732604 4338681 8871524 100759 6861603 680355 4724518 6032214 2344956 8509028 1512690 5789972 5026824 7951094 3610073 602116 3767862 8481451 5006073 7816562 2092288 5953086 523068 9518112 3464215 2789693 1082269 8009053 8299413 7075943 6997027 4622726 8040160 6442199 5687118 4983617 9947621 2673267 2793809 630635 8091709 2715376 4291752 8737080 2762351 3956320 7983365 8568024 2362566 3073125 3270724 6603689 4620937 9395672 1281470 8619935 8063360 7312770 8305899 7308943 6300279 2952216 2356665 2653451 4214804 9192057 5556983 1886793 4546386 5807019 2306902 6924370 205269 4728855 2787349 3283674 4189643 8054075 5751089 4160831 7800229 6732345 9176649 2103414 4048534 3384008 9242578 1008617 6022409 3431871 677001 8940164 8111501 2421803 9868695 9751360 7633981 269984 6614216 6239012 9427612 7188593 3688604 4861627 961079 5857476 3570060 9217780 5935153 4050742 2419387 3636231 4847598 6610200 4323987 4392380 6779003 874909 7922624 1653409 1884766 6010329 7167114 9530773 6130698 1044612 9243920 5501779 2473006 7102565 1951042 8884301 4224946 6278156 6689002 8839453 3259577 2103749 1077088 8768356 5645067 1295440 8116686 1748604 3332304 9404992 5589253 9866018 6760969 5220688 1207925 7480241 7331660 5512126 9826901 9734867 7639924 902456 9514356 9251982 7166381 3864069 6685234 8560354 2951607 1705603 4853746 7340927 892213 6772180 330778 697829 9889394 8161024 9366970 3630655 1230950 6759797 4637240 7586837 2881711 2558227 1960854 7017966 4789445 9971435 5911616 9306142 9241134 2141302 844881 1202664 6712670 5990196 57386 9458213 101089 2158942 270391 5290330 933854 5644789 2213594 3352148 4501022 7176126 3424082 8775341 9796006 9292722 9825360 5242916 4005910 2252662 6466845 3618030 2326314 1704599 7268377 3634091 7747131 726465 1062064 4964128 7301380 17682 2146554 7152013 7637808 459321 3100818 7201154 8476356 1017190 8208231 405559 3442173 8715479 9899371 7000664 3723460 4545711 7710148 2296155 9273786 2237578 7244429 8104293 161588 1514406 5375088 4143240 9911730 7349610 7876374 2270647 2033801 6844921 9338890 7985471 3690528 8230750 2789547 5599758 703955 6780031 2880274 8745238 1869892 254824 9834599 5371961 6732326 4447099 4937566 4737820 1312938 6870587 6519858 6498861 7273285 4716528 5765443 3686897 3230314 6775602 4628090 9760144 4722930 5127205 3824596 7415158 2931421 7436090 9146008 5892865 3841420 5554982 7314609 3302363 3156977 1456414 57333 3501003 8981853 3748555 5977370 6056495 5253115 4447042 475301 4099134 5627500 55950 7385476 3100 1979865 7082948 7090248 9446695 6361909 8529942 3364052 927859 8231946 5292509 650620 9943225 6688957 6909598 7357131 1978071 4443930 8445452 5614774 7638936 8004014 3700080 7255394 5419566 4758103 4650658 799412 1963182 448839 1897689 2267554 2630900 9818262 4599989 8107306 23674 1110111 379430 1995637 8113328 1354645 2327573 1210829 9814034 1467032 6657845 3409607 3301831 2585757 8308588 2349824 7935505 3603384 1398818 884234 6853971 8623896 7013780 7490374 7049705 6101853 8049061 9506028 5862018 3678037 7542694 2013628 3746775 6345169 2333162 6895653 1113056 3162179 1642682 6944323 7016606 6751890 2702825 8888511 5226567 8491905 7877828 3859199 2123362 5361106 363769 5898074 7565933 7937920 7731441 4700567 3669983 7590954 9938035 8778233 8295448 2977699 3006354 560293 2031908 8434843 858347 8342332 6038987 3388834 3139833 7871424 6491448 9237183 1300575 5862340 2167305 1709819 7682600 3810789 9710526 7086131 8349730 6039266 4593902 2894009 6201775 3165540 1673643 1983293 4686875 6916088 9080578 5897158 3359101 5462987 3869366 3417656 124172 8583562 1485439 7737486 932463 7034072 1533199 6575129 1620442 6551692 1117432 1491154 5460295 3862782 3796218 7691069 9453280 8657760 9843017 3129340 8507236 7871568 9814542 7805777 3009560 6023410 3657213 5249008 4540797 722119 3649825 8424924 7873083 6396718 6543087 2855039 8090135 9957535 1581917 7865793 5820009 5452508 3421644 877843 3630605 7304746 4518685 8283319 4110589 2431565 7238686 2529878 421239 249153 1527459 9807618 4233526 964753 6789972 5558371 7531208 7628823 1871023 7228240 5224760 6696540 6375292 6463459 2986602 4619851 1716989 3732824 3759448 2934205 8144385 7653949 7410930 4637181 4155758 5554415 2264638 366188 8864941 4955122 7949332 5741507 3552960 7241703 5108269 8198014 8850901 1821484 6843244 7571173 4087903 2046909 4625601 5102408 7347885 2563136 7230264 9392617 2174124 8495867 3334209 3038839 9655453 2022130 2067215 1876258 2651721 3423418 3777177 746511 2659195 2617876 5627260 5305578 9739060 5129398 2687131 7836855 5135719 9309046 4018097 2371814 7167627 5285474 9961102 8913640 8110995 8856998 8212080 4219295 2641742 1948933 2284373 6239768 5401246 9830474 8708102 4383548 7350339 2605756 9475319 6115868 8102500 9372180 7619491 9221996 9103028 4857956 6193810 5219187 6310538 9839965 5547081 3455710 6154521 471854 6680396 3177674 9971891 53225 4883340 4566460 4523792 2636118 8867872 8401165 6209613 9057590 7081144 695538 2596352 1105731 2942408 8391368 4014345 71469 7987103 8759801 4772702 2123735 7745882 5753673 3243832 378120 835412 5707941 4291522 2800923 2473651 8755624 9989168 2482093 3351250 4762292 8503994 5222769 635711 3479672 1224148 2210089 4452989 293332 7423255 4168350 9468566 6045896 2747065 8022443 42693 9521933 6096866 4216106 1546677 9041458 1511034

# INT_MAX & INT_MIN
# NUMBERS = -2147483648 2147483647 -2147483647

# Random
NUMBERS = 4 42 8 23 15 16
# NUMBERS = 1 5 2 4 3
# NUMBERS = 5 0 6 2 -45 -76 7 9 -5 -89 -23 -6 1
# NUMBERS = 4 8 15 16 23 42 -42
# NUMBERS = 1

EXEC = push_swap
CC = cc
CFLAGS =# -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

${EXEC}:	${OBJS} 
		+$(MAKE) -C libft
		gcc -o ${EXEC} ${CFLAGS} ${OBJS} ${LIBS}

all:	${EXEC}

operations:
	./push_swap ${NUMBERS} | wc -l

visualisation: all
		+$(MAKE) -C libft
		clear
		gcc -o .visualisation ${CFLAGS} -D VISUALISATION=1 ${SRCS} ${LIBS}
		./.visualisation ${NUMBERS}
		./push_swap ${NUMBERS} | wc -l
		rm -f ${OBJS} {EXEC} .visualisation

manual:
		+$(MAKE) -C libft
		clear
		gcc -o push_swap ${CFLAGS} -D VISUALISATION=1 -D MANUAL=1 ${SRCS} ${LIBS}
		./push_swap ${NUMBERS}
		rm -f ${OBJS} {EXEC}

run: all
	rm -f ${OBJS} {EXEC}
	./push_swap ${NUMBERS}
	./push_swap ${NUMBERS} | ./checker_linux ${NUMBERS}
	./push_swap ${NUMBERS} | wc -l

run_macos: all
	rm -f ${OBJS} {EXEC}
	./push_swap ${NUMBERS}
	./push_swap ${NUMBERS} | ./checker_Mac ${NUMBERS}
	./push_swap ${NUMBERS} | wc -l

clean:	
		+$(MAKE) -C libft clean
		rm -f ${OBJS} 

fclean:	clean;
		+$(MAKE) -C libft fclean
		rm -f ${EXEC}

re:	fclean all

norminette:
		norminette srcs/
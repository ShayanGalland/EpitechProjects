#!/usr/bin/env python3
import sys
import math
import random
from statistics import median, median_low, median_high

def display_help():
    print("SYNOPSIS")
    print("\t./groundhog period")
    print("")
    print("DESCRIPTION")
    print("\tperiod\tthe number of days defining a period")

def parse_args():
    if len(sys.argv) != 2:
        sys.exit(84)
    if sys.argv[1] == "-h":
        display_help()
        sys.exit(0)
    try:
        return int(sys.argv[1])
    except ValueError:
        sys.exit(84)

def calculate_g(temp_list, days):
    if len(temp_list) > days:
        g = sum(max(temp_list[i] - temp_list[i - 1], 0) for i in range(len(temp_list) - days, len(temp_list))) / days
        return round(g, 2)
    return "nan"

def calculate_r(temp_list, days):
    if len(temp_list) > days:
        last_temp = temp_list[-days - 1]
        current_temp = temp_list[-1]
        r = 0 if last_temp == 0 else round((current_temp - last_temp) / last_temp * 100)
        return r
    return "nan"

def calculate_s(temp_list, days):
    if len(temp_list) >= days:
        end = len(temp_list)
        x = sum(temp_list[i] for i in range(end - days, end))
        y = sum(temp_list[i] ** 2 for i in range(end - days, end))
        s = math.sqrt(y / days - (x / days) ** 2)
        return round(s, 2)
    return "nan"

def temp_switched(r_old, r_new):
    return r_old != "nan" and ((r_old < 0 and r_new > 0) or (r_old > 0 and r_new < 0))

def get_weirdest_values(temp_list, days):
    weirdest_values = []
    if len(temp_list) >= days:
        last_period_values = temp_list[-days:]
        sorted_values = sorted(last_period_values)
        #median_value = median(sorted_values)
        q1 = sorted_values[len(sorted_values) // 4]
        q3 = sorted_values[3 * len(sorted_values) // 4]
        iqr = q3 - q1
        lower_limit = q1 - 0.8 * iqr
        upper_limit = q3 + 0.8 * iqr
        weirdest_values = [value for value in last_period_values if value < lower_limit or value > upper_limit]
    return weirdest_values

def get_top_weirdest(temp_list, weirdest_values):
    if len(weirdest_values) > 0:
        avg = sum(weirdest_values) / len(weirdest_values)
        top_weirdest = sorted(weirdest_values, key=lambda x: abs(x - avg) ** 2, reverse=True)[:5]
        return top_weirdest
    return []

def main():
    days = parse_args()
    temp_list = []
    switch_count = 0
    r_old = "nan"

    while True:
        try:
            user_input = input()
        except (EOFError, KeyError):
            sys.exit(84)

        if user_input == "STOP":
            if len(temp_list) < days:
                sys.exit(84)

            print(f"Global tendency switched {switch_count} times")
            if switch_count > 0:
                top_weirdest = get_top_weirdest(temp_list, get_weirdest_values(temp_list, days))
                print("5 weirdest values are", top_weirdest)
                sys.exit(0)
        try:
            temp_input = float(user_input)
        except ValueError:
            sys.exit(84)

        temp_list.append(temp_input)

        g = calculate_g(temp_list, days)
        r_new = calculate_r(temp_list, days)
        s = calculate_s(temp_list, days)

        output = f"g={g}\tr={r_new}%\ts={s:.2f}" if isinstance(s, float) else f"g={g}\tr={r_new}%\ts={s}"


        if temp_switched(r_old, r_new):
            output += "\ta switch occurs"
            switch_count += 1
        print(output)

        r_old = r_new


if __name__ == "__main__":
    main()

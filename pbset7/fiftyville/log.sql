-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Looking into the crime reports table

SELECT * FROM crime_scene_reports
WHERE street = "Chamberlin Street" AND day = 28;

--Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.
--10:15am three witnesses

SELECT * FROM interviews
WHERE day = 28 AND month = 07;

--Mr. Windibank || German accent
--Within ten minutes of the theft the thief got in to a car and drove away CHECK
--Earlier the thief withdrawn money from ATM on Fifer street CHECK
--Thief call someone and talked for less than a minute || going to take the earliest flight out of Fiftyville tomorrow || Asked the person to purchase the tickets


SELECT * FROM courthouse_security_logs
WHERE day = 28 AND month = 07 AND hour = 10 AND minute BETWEEN 15 AND 25;

--Cars that left the courthouse in the timeframe

--260 | 2020 | 7 | 28 | 10 | 16 | exit | 5P2BI95
--261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X
--262 | 2020 | 7 | 28 | 10 | 18 | exit | 6P58WS2
--263 | 2020 | 7 | 28 | 10 | 19 | exit | 4328GD8
--264 | 2020 | 7 | 28 | 10 | 20 | exit | G412CB7
--265 | 2020 | 7 | 28 | 10 | 21 | exit | L93JTIZ
--266 | 2020 | 7 | 28 | 10 | 23 | exit | 322W7JE
--267 | 2020 | 7 | 28 | 10 | 23 | exit | 0NTHK55

SELECT * FROM atm_transactions
WHERE day = 28 AND month = 07 AND transaction_type = "withdraw" AND atm_location = "Fifer Street";

/* Accounts that withdrawn on Fifer Street that day
246 | 28500762 | 2020 | 7 | 28 | Fifer Street | withdraw | 48
264 | 28296815 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
266 | 76054385 | 2020 | 7 | 28 | Fifer Street | withdraw | 60
267 | 49610011 | 2020 | 7 | 28 | Fifer Street | withdraw | 50
269 | 16153065 | 2020 | 7 | 28 | Fifer Street | withdraw | 80
288 | 25506511 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
313 | 81061156 | 2020 | 7 | 28 | Fifer Street | withdraw | 30
336 | 26013199 | 2020 | 7 | 28 | Fifer Street | withdraw | 35
*/

SELECT * FROM phone_calls
WHERE day = 28 AND month = 07 AND duration < 60;

/* Phone calls with less than a minute
221 | (130) 555-0289 | (996) 555-8899 | 2020 | 7 | 28 | 51
224 | (499) 555-9472 | (892) 555-8872 | 2020 | 7 | 28 | 36
233 | (367) 555-5533 | (375) 555-8161 | 2020 | 7 | 28 | 45
251 | (499) 555-9472 | (717) 555-1342 | 2020 | 7 | 28 | 50
254 | (286) 555-6063 | (676) 555-6554 | 2020 | 7 | 28 | 43
255 | (770) 555-1861 | (725) 555-3243 | 2020 | 7 | 28 | 49
261 | (031) 555-6622 | (910) 555-3251 | 2020 | 7 | 28 | 38
279 | (826) 555-1652 | (066) 555-9701 | 2020 | 7 | 28 | 55
281 | (338) 555-6650 | (704) 555-2131 | 2020 | 7 | 28 | 54
*/

SELECT * FROM flights
WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29  AND month = 07
ORDER BY hour;


SELECT * FROM passengers
WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29  AND month = 07 ORDER BY hour LIMIT 1);

/* Passangers in the first flight out of Fiftyville in the day after the crime

flight_id | passport_number | seat
6 | 3835860232 | 9A
6 | 1618186613 | 2C
6 | 7179245843 | 3B
6 | 1682575122 | 4B
6 | 7597790505 | 5D
6 | 6128131458 | 6B
6 | 6264773605 | 7D
6 | 3642612721 | 8A

*/

SELECT * FROM people
WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29  AND month = 07 ORDER BY hour LIMIT 1))
AND phone_number IN (SELECT caller FROM phone_calls WHERE day = 28 AND month = 07 AND duration < 60)
AND license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE day = 28 AND month = 07 AND hour = 10 AND minute BETWEEN 15 AND 25);

/*
id | name | phone_number | passport_number | license_plate
398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7
560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
*/


SELECT * FROM people 
WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29  AND month = 07 ORDER BY hour LIMIT 1))
AND phone_number IN (SELECT caller FROM phone_calls WHERE day = 28 AND month = 07 AND duration < 60)
AND license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE day = 28 AND month = 07 AND hour = 10 AND minute BETWEEN 15 AND 25)
AND id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 07 AND transaction_type = "withdraw" AND atm_location = "Fifer Street"));

--Thief
--686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X

SELECT receiver FROM phone_calls
WHERE caller = (SELECT phone_number FROM people 
WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29  AND month = 07 ORDER BY hour LIMIT 1))
AND phone_number IN (SELECT caller FROM phone_calls WHERE day = 28 AND month = 07 AND duration < 60)
AND license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE day = 28 AND month = 07 AND hour = 10 AND minute BETWEEN 15 AND 25)
AND id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 07 AND transaction_type = "withdraw" AND atm_location = "Fifer Street")))
AND day = 28 AND month = 07 AND duration < 60;

SELECT * FROM people
WHERE phone_number = (SELECT receiver FROM phone_calls
WHERE caller = (SELECT phone_number FROM people 
WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29  AND month = 07 ORDER BY hour LIMIT 1))
AND phone_number IN (SELECT caller FROM phone_calls WHERE day = 28 AND month = 07 AND duration < 60)
AND license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE day = 28 AND month = 07 AND hour = 10 AND minute BETWEEN 15 AND 25)
AND id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 07 AND transaction_type = "withdraw" AND atm_location = "Fifer Street")))
AND day = 28 AND month = 07 AND duration < 60);

--Compliance : 
--864400 | Berthold | (375) 555-8161 |  | 4V16VO0

SELECT city FROM airports
WHERE id IN (SELECT destination_airport_id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29  AND month = 07 ORDER BY hour LIMIT 1);
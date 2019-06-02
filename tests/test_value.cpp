#define BOOST_TEST_MODULE "test_value"
#ifdef UNITTEST_FRAMEWORK_LIBRARY_EXIST
#include <boost/test/unit_test.hpp>
#else
#define BOOST_TEST_NO_LIB
#include <boost/test/included/unit_test.hpp>
#endif
#include <toml/value.hpp>
#include <map>
#include <list>

#if __cplusplus >= 201703L
#include <string_view>
#endif


BOOST_AUTO_TEST_CASE(test_value_boolean)
{
    toml::value v1(true);
    toml::value v2(false);

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::boolean);
    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::boolean);
    BOOST_CHECK(v1.is(toml::value_t::boolean));
    BOOST_CHECK(v2.is(toml::value_t::boolean));
    BOOST_CHECK(v1.is<toml::boolean>());
    BOOST_CHECK(v2.is<toml::boolean>());
    BOOST_CHECK(v1.is_boolean());
    BOOST_CHECK(v2.is_boolean());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::boolean>(), true);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::boolean>(), false);
    BOOST_CHECK_EQUAL(v1.as_boolean(), true);
    BOOST_CHECK_EQUAL(v2.as_boolean(), false);

    v1 = false;
    v2 = true;

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::boolean);
    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::boolean);
    BOOST_CHECK(v1.is(toml::value_t::boolean));
    BOOST_CHECK(v2.is(toml::value_t::boolean));
    BOOST_CHECK(v1.is<toml::boolean>());
    BOOST_CHECK(v2.is<toml::boolean>());
    BOOST_CHECK(v1.is_boolean());
    BOOST_CHECK(v2.is_boolean());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::boolean>(), false);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::boolean>(), true);
    BOOST_CHECK_EQUAL(v1.as_boolean(), false);
    BOOST_CHECK_EQUAL(v2.as_boolean(), true);

    toml::value v3(v1);
    toml::value v4(v2);
    BOOST_CHECK(v3 == v1);
    BOOST_CHECK(v4 == v2);

    BOOST_CHECK_EQUAL(v3.type(), toml::value_t::boolean);
    BOOST_CHECK_EQUAL(v4.type(), toml::value_t::boolean);
    BOOST_CHECK(v3.is(toml::value_t::boolean));
    BOOST_CHECK(v4.is(toml::value_t::boolean));
    BOOST_CHECK(v3.is<toml::boolean>());
    BOOST_CHECK(v4.is<toml::boolean>());
    BOOST_CHECK(v3.is_boolean());
    BOOST_CHECK(v4.is_boolean());

    BOOST_CHECK_EQUAL(v3.cast<toml::value_t::boolean>(), false);
    BOOST_CHECK_EQUAL(v4.cast<toml::value_t::boolean>(), true);
    BOOST_CHECK_EQUAL(v3.as_boolean(), false);
    BOOST_CHECK_EQUAL(v4.as_boolean(), true);

    toml::value v5(std::move(v1));
    toml::value v6(std::move(v2));

    BOOST_CHECK_EQUAL(v5.type(), toml::value_t::boolean);
    BOOST_CHECK_EQUAL(v6.type(), toml::value_t::boolean);
    BOOST_CHECK(v5.is(toml::value_t::boolean));
    BOOST_CHECK(v6.is(toml::value_t::boolean));
    BOOST_CHECK(v5.is<toml::boolean>());
    BOOST_CHECK(v6.is<toml::boolean>());
    BOOST_CHECK(v3.is_boolean());
    BOOST_CHECK(v4.is_boolean());

    BOOST_CHECK_EQUAL(v5.cast<toml::value_t::boolean>(), false);
    BOOST_CHECK_EQUAL(v6.cast<toml::value_t::boolean>(), true);
    BOOST_CHECK_EQUAL(v5.as_boolean(), false);
    BOOST_CHECK_EQUAL(v6.as_boolean(), true);

    v1 = 42;
    v2 = 3.14;

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::integer);
    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::floating);
    BOOST_CHECK(v1.is(toml::value_t::integer));
    BOOST_CHECK(v2.is(toml::value_t::floating));
    BOOST_CHECK(v1.is<toml::integer>());
    BOOST_CHECK(v2.is<toml::floating>());
    BOOST_CHECK(v1.is_integer());
    BOOST_CHECK(v2.is_float());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::integer>(), 42);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::floating>(),   3.14);
    BOOST_CHECK_EQUAL(v1.as_integer(),  42);
    BOOST_CHECK_EQUAL(v2.as_float(), 3.14);
}

BOOST_AUTO_TEST_CASE(test_value_integer)
{
    toml::value v1(-42);
    toml::value v2(42u);

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::integer);
    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::integer);
    BOOST_CHECK(v1.is(toml::value_t::integer));
    BOOST_CHECK(v2.is(toml::value_t::integer));
    BOOST_CHECK(v1.is<toml::integer>());
    BOOST_CHECK(v2.is<toml::integer>());
    BOOST_CHECK(v1.is_integer());
    BOOST_CHECK(v2.is_integer());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::integer>(), -42);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::integer>(),  42u);
    BOOST_CHECK_EQUAL(v1.as_integer(), -42);
    BOOST_CHECK_EQUAL(v2.as_integer(),  42u);

    v1 = 54;
    v2 = -54;

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::integer);
    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::integer);
    BOOST_CHECK(v1.is(toml::value_t::integer));
    BOOST_CHECK(v2.is(toml::value_t::integer));
    BOOST_CHECK(v1.is<toml::integer>());
    BOOST_CHECK(v2.is<toml::integer>());
    BOOST_CHECK(v1.is_integer());
    BOOST_CHECK(v2.is_integer());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::integer>(),  54);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::integer>(), -54);
    BOOST_CHECK_EQUAL(v1.as_integer(),  54);
    BOOST_CHECK_EQUAL(v2.as_integer(), -54);

    toml::value v3(v1);
    toml::value v4(v2);
    BOOST_CHECK(v3 == v1);
    BOOST_CHECK(v4 == v2);

    BOOST_CHECK_EQUAL(v3.type(), toml::value_t::integer);
    BOOST_CHECK_EQUAL(v4.type(), toml::value_t::integer);
    BOOST_CHECK(v3.is(toml::value_t::integer));
    BOOST_CHECK(v4.is(toml::value_t::integer));
    BOOST_CHECK(v3.is<toml::integer>());
    BOOST_CHECK(v4.is<toml::integer>());
    BOOST_CHECK(v3.is_integer());
    BOOST_CHECK(v4.is_integer());

    BOOST_CHECK_EQUAL(v3.cast<toml::value_t::integer>(),  54);
    BOOST_CHECK_EQUAL(v4.cast<toml::value_t::integer>(), -54);
    BOOST_CHECK_EQUAL(v3.as_integer(),  54);
    BOOST_CHECK_EQUAL(v4.as_integer(), -54);

    toml::value v5(std::move(v1));
    toml::value v6(std::move(v2));

    BOOST_CHECK_EQUAL(v5.type(), toml::value_t::integer);
    BOOST_CHECK_EQUAL(v6.type(), toml::value_t::integer);
    BOOST_CHECK(v5.is(toml::value_t::integer));
    BOOST_CHECK(v6.is(toml::value_t::integer));
    BOOST_CHECK(v5.is<toml::integer>());
    BOOST_CHECK(v6.is<toml::integer>());
    BOOST_CHECK(v5.is_integer());
    BOOST_CHECK(v6.is_integer());

    BOOST_CHECK_EQUAL(v5.cast<toml::value_t::integer>(),  54);
    BOOST_CHECK_EQUAL(v6.cast<toml::value_t::integer>(), -54);
    BOOST_CHECK_EQUAL(v5.as_integer(),  54);
    BOOST_CHECK_EQUAL(v6.as_integer(), -54);

    v1 = true;
    v2 = false;

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::boolean);
    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::boolean);
    BOOST_CHECK(v1.is(toml::value_t::boolean));
    BOOST_CHECK(v2.is(toml::value_t::boolean));
    BOOST_CHECK(v1.is<toml::boolean>());
    BOOST_CHECK(v2.is<toml::boolean>());
    BOOST_CHECK(v1.is_boolean());
    BOOST_CHECK(v2.is_boolean());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::boolean>(), true);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::boolean>(), false);
    BOOST_CHECK_EQUAL(v1.as_boolean(), true);
    BOOST_CHECK_EQUAL(v2.as_boolean(), false);
}

BOOST_AUTO_TEST_CASE(test_value_float)
{
    toml::value v1(3.14);
    toml::value v2(3.14f);

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::floating);
    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::floating);
    BOOST_CHECK(v1.is(toml::value_t::floating));
    BOOST_CHECK(v2.is(toml::value_t::floating));
    BOOST_CHECK(v1.is<toml::floating>());
    BOOST_CHECK(v2.is<toml::floating>());
    BOOST_CHECK(v1.is_float());
    BOOST_CHECK(v2.is_float());

    BOOST_CHECK_EQUAL         (v1.cast<toml::value_t::floating>(), 3.14);
    BOOST_CHECK_CLOSE_FRACTION(v2.cast<toml::value_t::floating>(), 3.14, 1e-2);
    BOOST_CHECK_EQUAL         (v1.as_float(), 3.14);
    BOOST_CHECK_CLOSE_FRACTION(v2.as_float(), 3.14, 1e-2);

    v1 = 2.718f;
    v2 = 2.718;

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::floating);
    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::floating);
    BOOST_CHECK(v1.is(toml::value_t::floating));
    BOOST_CHECK(v2.is(toml::value_t::floating));
    BOOST_CHECK(v1.is<toml::floating>());
    BOOST_CHECK(v2.is<toml::floating>());
    BOOST_CHECK(v1.is_float());
    BOOST_CHECK(v2.is_float());

    BOOST_CHECK_CLOSE_FRACTION(v1.cast<toml::value_t::floating>(), 2.718, 1e-3);
    BOOST_CHECK_EQUAL         (v2.cast<toml::value_t::floating>(), 2.718);
    BOOST_CHECK_CLOSE_FRACTION(v1.as_float(), 2.718, 1e-3);
    BOOST_CHECK_EQUAL         (v2.as_float(), 2.718);

    toml::value v3(v1);
    toml::value v4(v2);
    BOOST_CHECK(v3 == v1);
    BOOST_CHECK(v4 == v2);

    BOOST_CHECK_EQUAL(v3.type(), toml::value_t::floating);
    BOOST_CHECK_EQUAL(v4.type(), toml::value_t::floating);
    BOOST_CHECK(v3.is(toml::value_t::floating));
    BOOST_CHECK(v4.is(toml::value_t::floating));
    BOOST_CHECK(v3.is<toml::floating>());
    BOOST_CHECK(v4.is<toml::floating>());
    BOOST_CHECK(v3.is_float());
    BOOST_CHECK(v4.is_float());

    BOOST_CHECK_CLOSE_FRACTION(v3.cast<toml::value_t::floating>(), 2.718, 1e-3);
    BOOST_CHECK_EQUAL         (v4.cast<toml::value_t::floating>(), 2.718);
    BOOST_CHECK_CLOSE_FRACTION(v3.as_float(), 2.718, 1e-3);
    BOOST_CHECK_EQUAL         (v4.as_float(), 2.718);

    toml::value v5(std::move(v1));
    toml::value v6(std::move(v2));

    BOOST_CHECK_EQUAL(v5.type(), toml::value_t::floating);
    BOOST_CHECK_EQUAL(v6.type(), toml::value_t::floating);
    BOOST_CHECK(v5.is(toml::value_t::floating));
    BOOST_CHECK(v6.is(toml::value_t::floating));
    BOOST_CHECK(v5.is<toml::floating>());
    BOOST_CHECK(v6.is<toml::floating>());
    BOOST_CHECK(v5.is_float());
    BOOST_CHECK(v6.is_float());

    BOOST_CHECK_CLOSE_FRACTION(v5.cast<toml::value_t::floating>(), 2.718, 1e-3);
    BOOST_CHECK_EQUAL         (v6.cast<toml::value_t::floating>(), 2.718);
    BOOST_CHECK_CLOSE_FRACTION(v5.as_float(), 2.718, 1e-3);
    BOOST_CHECK_EQUAL         (v6.as_float(), 2.718);

    v1 = true;
    v2 = false;

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::boolean);
    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::boolean);
    BOOST_CHECK(v1.is(toml::value_t::boolean));
    BOOST_CHECK(v2.is(toml::value_t::boolean));
    BOOST_CHECK(v1.is<toml::boolean>());
    BOOST_CHECK(v2.is<toml::boolean>());
    BOOST_CHECK(v1.is_boolean());
    BOOST_CHECK(v2.is_boolean());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::boolean>(), true);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::boolean>(), false);
    BOOST_CHECK_EQUAL(v1.as_boolean(), true);
    BOOST_CHECK_EQUAL(v2.as_boolean(), false);
}

BOOST_AUTO_TEST_CASE(test_value_string)
{
    toml::value v1(std::string("foo"));
    toml::value v2(std::string("foo"), toml::string_t::literal);
    toml::value v3("foo");

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::string);
    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::string);
    BOOST_CHECK_EQUAL(v3.type(), toml::value_t::string);
    BOOST_CHECK(v1.is(toml::value_t::string));
    BOOST_CHECK(v2.is(toml::value_t::string));
    BOOST_CHECK(v3.is(toml::value_t::string));
    BOOST_CHECK(v1.is<toml::string>());
    BOOST_CHECK(v2.is<toml::string>());
    BOOST_CHECK(v3.is<toml::string>());
    BOOST_CHECK(v1.is_string());
    BOOST_CHECK(v2.is_string());
    BOOST_CHECK(v3.is_string());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::string>(), "foo");
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::string>(), "foo");
    BOOST_CHECK_EQUAL(v3.cast<toml::value_t::string>(), "foo");
    BOOST_CHECK_EQUAL(v1.as_string(), "foo");
    BOOST_CHECK_EQUAL(v2.as_string(), "foo");
    BOOST_CHECK_EQUAL(v3.as_string(), "foo");


    v1 = "bar";
    v2 = "bar";
    v3 = "bar";

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::string);
    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::string);
    BOOST_CHECK_EQUAL(v3.type(), toml::value_t::string);
    BOOST_CHECK(v1.is(toml::value_t::string));
    BOOST_CHECK(v2.is(toml::value_t::string));
    BOOST_CHECK(v3.is(toml::value_t::string));
    BOOST_CHECK(v1.is_string());
    BOOST_CHECK(v2.is_string());
    BOOST_CHECK(v3.is_string());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::string>(), "bar");
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::string>(), "bar");
    BOOST_CHECK_EQUAL(v3.cast<toml::value_t::string>(), "bar");
    BOOST_CHECK_EQUAL(v1.as_string(), "bar");
    BOOST_CHECK_EQUAL(v2.as_string(), "bar");
    BOOST_CHECK_EQUAL(v3.as_string(), "bar");


    toml::value v4(v1);
    toml::value v5(v2);
    toml::value v6(v3);
    BOOST_CHECK(v4 == v1);
    BOOST_CHECK(v5 == v2);
    BOOST_CHECK(v6 == v3);

    BOOST_CHECK_EQUAL(v4.type(), toml::value_t::string);
    BOOST_CHECK_EQUAL(v5.type(), toml::value_t::string);
    BOOST_CHECK_EQUAL(v6.type(), toml::value_t::string);
    BOOST_CHECK(v4.is(toml::value_t::string));
    BOOST_CHECK(v5.is(toml::value_t::string));
    BOOST_CHECK(v6.is(toml::value_t::string));
    BOOST_CHECK(v4.is<toml::string>());
    BOOST_CHECK(v5.is<toml::string>());
    BOOST_CHECK(v6.is<toml::string>());
    BOOST_CHECK(v4.is_string());
    BOOST_CHECK(v5.is_string());
    BOOST_CHECK(v6.is_string());

    BOOST_CHECK_EQUAL(v4.cast<toml::value_t::string>(), "bar");
    BOOST_CHECK_EQUAL(v5.cast<toml::value_t::string>(), "bar");
    BOOST_CHECK_EQUAL(v6.cast<toml::value_t::string>(), "bar");
    BOOST_CHECK_EQUAL(v4.as_string(), "bar");
    BOOST_CHECK_EQUAL(v5.as_string(), "bar");
    BOOST_CHECK_EQUAL(v6.as_string(), "bar");


    v4.cast<toml::value_t::string>().str.at(2) = 'z';
    v5.cast<toml::value_t::string>().str.at(2) = 'z';
    v6.cast<toml::value_t::string>().str.at(2) = 'z';

    BOOST_CHECK_EQUAL(v4.type(), toml::value_t::string);
    BOOST_CHECK_EQUAL(v5.type(), toml::value_t::string);
    BOOST_CHECK_EQUAL(v6.type(), toml::value_t::string);
    BOOST_CHECK(v4.is(toml::value_t::string));
    BOOST_CHECK(v5.is(toml::value_t::string));
    BOOST_CHECK(v6.is(toml::value_t::string));
    BOOST_CHECK(v4.is<toml::string>());
    BOOST_CHECK(v5.is<toml::string>());
    BOOST_CHECK(v6.is<toml::string>());
    BOOST_CHECK(v4.is_string());
    BOOST_CHECK(v5.is_string());
    BOOST_CHECK(v6.is_string());

    BOOST_CHECK_EQUAL(v4.as_string(), "baz");
    BOOST_CHECK_EQUAL(v5.as_string(), "baz");
    BOOST_CHECK_EQUAL(v6.as_string(), "baz");

    v1 = true;
    v2 = true;
    v3 = true;

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::boolean);
    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::boolean);
    BOOST_CHECK_EQUAL(v3.type(), toml::value_t::boolean);
    BOOST_CHECK(v1.is(toml::value_t::boolean));
    BOOST_CHECK(v2.is(toml::value_t::boolean));
    BOOST_CHECK(v3.is(toml::value_t::boolean));
    BOOST_CHECK(v1.is<toml::boolean>());
    BOOST_CHECK(v2.is<toml::boolean>());
    BOOST_CHECK(v3.is<toml::boolean>());
    BOOST_CHECK(v1.is_boolean());
    BOOST_CHECK(v2.is_boolean());
    BOOST_CHECK(v3.is_boolean());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::boolean>(), true);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::boolean>(), true);
    BOOST_CHECK_EQUAL(v3.cast<toml::value_t::boolean>(), true);
    BOOST_CHECK_EQUAL(v1.as_boolean(), true);
    BOOST_CHECK_EQUAL(v2.as_boolean(), true);
    BOOST_CHECK_EQUAL(v3.as_boolean(), true);

#if __cplusplus >= 201703L
    std::string_view sv = "foo";

    toml::value v7(sv);
    toml::value v8(sv, toml::string_t::literal);

    BOOST_CHECK_EQUAL(v7.type(), toml::value_t::string);
    BOOST_CHECK_EQUAL(v8.type(), toml::value_t::string);
    BOOST_CHECK(v7.is(toml::value_t::string));
    BOOST_CHECK(v8.is(toml::value_t::string));
    BOOST_CHECK(v7.is<toml::string>());
    BOOST_CHECK(v8.is<toml::string>());
    BOOST_CHECK(v7.is_string());
    BOOST_CHECK(v8.is_string());

    BOOST_CHECK_EQUAL(v7.cast<toml::value_t::string>(), "foo");
    BOOST_CHECK_EQUAL(v8.cast<toml::value_t::string>(), "foo");
#endif
}

BOOST_AUTO_TEST_CASE(test_value_local_date)
{
    toml::value v1(toml::local_date(2018, toml::month_t::Jan, 31));

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::local_date);
    BOOST_CHECK(v1.is(toml::value_t::local_date));
    BOOST_CHECK(v1.is<toml::local_date>());
    BOOST_CHECK(v1.is_local_date());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::local_date>(),
                      toml::local_date(2018, toml::month_t::Jan, 31));
    BOOST_CHECK_EQUAL(v1.as_local_date(),
                      toml::local_date(2018, toml::month_t::Jan, 31));

    v1 = toml::local_date(2018, toml::month_t::Apr, 1);

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::local_date);
    BOOST_CHECK(v1.is(toml::value_t::local_date));
    BOOST_CHECK(v1.is<toml::local_date>());
    BOOST_CHECK(v1.is_local_date());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::local_date>(),
                      toml::local_date(2018, toml::month_t::Apr, 1));
    BOOST_CHECK_EQUAL(v1.as_local_date(),
                      toml::local_date(2018, toml::month_t::Apr, 1));

    toml::value v2(v1);
    BOOST_CHECK(v2 == v1);

    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::local_date);
    BOOST_CHECK(v2.is(toml::value_t::local_date));
    BOOST_CHECK(v2.is<toml::local_date>());
    BOOST_CHECK(v2.is_local_date());

    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::local_date>(),
                      toml::local_date(2018, toml::month_t::Apr, 1));
    BOOST_CHECK_EQUAL(v2.as_local_date(),
                      toml::local_date(2018, toml::month_t::Apr, 1));

    v1 = true;
    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::boolean);
    BOOST_CHECK(v1.is(toml::value_t::boolean));
    BOOST_CHECK(v1.is<toml::boolean>());
    BOOST_CHECK(v1.is_boolean());
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::boolean>(), true);
    BOOST_CHECK_EQUAL(v1.as_boolean(), true);
}

BOOST_AUTO_TEST_CASE(test_value_local_time)
{
    toml::value v1(toml::local_time(12, 30, 45));
    toml::value v2(std::chrono::hours(12) + std::chrono::minutes(30) +
                   std::chrono::seconds(45));

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::local_time);
    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::local_time);
    BOOST_CHECK(v1.is(toml::value_t::local_time));
    BOOST_CHECK(v2.is(toml::value_t::local_time));
    BOOST_CHECK(v1.is<toml::local_time>());
    BOOST_CHECK(v2.is<toml::local_time>());
    BOOST_CHECK(v1.is_local_time());
    BOOST_CHECK(v2.is_local_time());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::local_time>(),
                      toml::local_time(12, 30, 45));
    BOOST_CHECK_EQUAL(v1.as_local_time(),
                      toml::local_time(12, 30, 45));

    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::local_time>(),
                      toml::local_time(12, 30, 45));
    BOOST_CHECK_EQUAL(v2.as_local_time(),
                      toml::local_time(12, 30, 45));

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::local_time>(),
                      v2.cast<toml::value_t::local_time>());
    BOOST_CHECK_EQUAL(v1.as_local_time(),
                      v2.as_local_time());

    v1 = toml::local_time(1, 30, 0, /*ms*/ 100, /*us*/ 0);

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::local_time);
    BOOST_CHECK(v1.is(toml::value_t::local_time));
    BOOST_CHECK(v1.is<toml::local_time>());
    BOOST_CHECK(v1.is_local_time());
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::local_time>(),
                      toml::local_time(1, 30, 0, 100, 0));
    BOOST_CHECK_EQUAL(v1.as_local_time(),
                      toml::local_time(1, 30, 0, 100, 0));

    toml::value v3(v1);
    BOOST_CHECK(v3 == v1);

    BOOST_CHECK_EQUAL(v3.type(), toml::value_t::local_time);
    BOOST_CHECK(v3.is(toml::value_t::local_time));
    BOOST_CHECK(v3.is<toml::local_time>());
    BOOST_CHECK(v3.is_local_time());

    BOOST_CHECK_EQUAL(v3.cast<toml::value_t::local_time>(),
                      toml::local_time(1, 30, 0, 100, 0));
    BOOST_CHECK_EQUAL(v3.as_local_time(),
                      toml::local_time(1, 30, 0, 100, 0));

    v1 = true;
    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::boolean);
    BOOST_CHECK(v1.is(toml::value_t::boolean));
    BOOST_CHECK(v1.is<toml::boolean>());
    BOOST_CHECK(v1.is_boolean());
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::boolean>(), true);
    BOOST_CHECK_EQUAL(v1.as_boolean(), true);
}

BOOST_AUTO_TEST_CASE(test_value_local_datetime)
{
    toml::value v1(toml::local_datetime(
                toml::local_date(2018, toml::month_t::Jan, 31),
                toml::local_time(12, 30, 45)
                ));

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::local_datetime);
    BOOST_CHECK(v1.is(toml::value_t::local_datetime));
    BOOST_CHECK(v1.is<toml::local_datetime>());
    BOOST_CHECK(v1.is_local_datetime());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::local_datetime>(),
                      toml::local_datetime(
                          toml::local_date(2018, toml::month_t::Jan, 31),
                          toml::local_time(12, 30, 45)));
    BOOST_CHECK_EQUAL(v1.as_local_datetime(),
                      toml::local_datetime(
                          toml::local_date(2018, toml::month_t::Jan, 31),
                          toml::local_time(12, 30, 45)));

    v1 = toml::local_datetime(
                toml::local_date(2018, toml::month_t::Apr, 1),
                toml::local_time(1, 15, 30));

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::local_datetime);
    BOOST_CHECK(v1.is(toml::value_t::local_datetime));
    BOOST_CHECK(v1.is<toml::local_datetime>());
    BOOST_CHECK(v1.is_local_datetime());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::local_datetime>(),
                      toml::local_datetime(
                          toml::local_date(2018, toml::month_t::Apr, 1),
                          toml::local_time(1, 15, 30)));
    BOOST_CHECK_EQUAL(v1.as_local_datetime(),
                      toml::local_datetime(
                          toml::local_date(2018, toml::month_t::Apr, 1),
                          toml::local_time(1, 15, 30)));

    toml::value v2(v1);
    BOOST_CHECK(v2 == v1);

    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::local_datetime);
    BOOST_CHECK(v2.is(toml::value_t::local_datetime));
    BOOST_CHECK(v2.is<toml::local_datetime>());
    BOOST_CHECK(v2.is_local_datetime());

    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::local_datetime>(),
                      toml::local_datetime(
                          toml::local_date(2018, toml::month_t::Apr, 1),
                          toml::local_time(1, 15, 30)));
    BOOST_CHECK_EQUAL(v2.as_local_datetime(),
                      toml::local_datetime(
                          toml::local_date(2018, toml::month_t::Apr, 1),
                          toml::local_time(1, 15, 30)));


    v1 = true;
    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::boolean);
    BOOST_CHECK(v1.is(toml::value_t::boolean));
    BOOST_CHECK(v1.is<toml::boolean>());
    BOOST_CHECK(v1.is_boolean());
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::boolean>(), true);
    BOOST_CHECK_EQUAL(v1.as_boolean(), true);
}

BOOST_AUTO_TEST_CASE(test_value_offset_datetime)
{
    toml::value v1(toml::offset_datetime(
                toml::local_date(2018, toml::month_t::Jan, 31),
                toml::local_time(12, 30, 45),
                toml::time_offset(9, 0)
                ));

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::offset_datetime);
    BOOST_CHECK(v1.is(toml::value_t::offset_datetime));
    BOOST_CHECK(v1.is<toml::offset_datetime>());
    BOOST_CHECK(v1.is_offset_datetime());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::offset_datetime>(),
            toml::offset_datetime(
                toml::local_date(2018, toml::month_t::Jan, 31),
                toml::local_time(12, 30, 45),
                toml::time_offset(9, 0)
                ));
    BOOST_CHECK_EQUAL(v1.as_offset_datetime(),
            toml::offset_datetime(
                toml::local_date(2018, toml::month_t::Jan, 31),
                toml::local_time(12, 30, 45),
                toml::time_offset(9, 0)
                ));

    v1 = toml::offset_datetime(
                toml::local_date(2018, toml::month_t::Apr, 1),
                toml::local_time(1, 15, 30),
                toml::time_offset(9, 0));

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::offset_datetime);
    BOOST_CHECK(v1.is(toml::value_t::offset_datetime));
    BOOST_CHECK(v1.is<toml::offset_datetime>());
    BOOST_CHECK(v1.is_offset_datetime());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::offset_datetime>(),
            toml::offset_datetime(
                toml::local_date(2018, toml::month_t::Apr, 1),
                toml::local_time(1, 15, 30),
                toml::time_offset(9, 0)));
    BOOST_CHECK_EQUAL(v1.as_offset_datetime(),
            toml::offset_datetime(
                toml::local_date(2018, toml::month_t::Apr, 1),
                toml::local_time(1, 15, 30),
                toml::time_offset(9, 0)));


    toml::value v2(v1);
    BOOST_CHECK(v2 == v1);

    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::offset_datetime);
    BOOST_CHECK(v2.is(toml::value_t::offset_datetime));
    BOOST_CHECK(v2.is<toml::offset_datetime>());
    BOOST_CHECK(v2.is_offset_datetime());

    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::offset_datetime>(),
            toml::offset_datetime(
                toml::local_date(2018, toml::month_t::Apr, 1),
                toml::local_time(1, 15, 30),
                toml::time_offset(9, 0)));
    BOOST_CHECK_EQUAL(v2.as_offset_datetime(),
            toml::offset_datetime(
                toml::local_date(2018, toml::month_t::Apr, 1),
                toml::local_time(1, 15, 30),
                toml::time_offset(9, 0)));

    v1 = true;
    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::boolean);
    BOOST_CHECK(v1.is(toml::value_t::boolean));
    BOOST_CHECK(v1.is<toml::boolean>());
    BOOST_CHECK(v1.is_boolean());
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::boolean>(), true);
    BOOST_CHECK_EQUAL(v1.as_boolean(), true);
}

BOOST_AUTO_TEST_CASE(test_value_array)
{
    std::vector<int> v{1,2,3,4,5};
    toml::value v1(v);
    toml::value v2{6,7,8,9,0};

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::array);
    BOOST_CHECK(v1.is(toml::value_t::array));
    BOOST_CHECK(v1.is<toml::array>());
    BOOST_CHECK(v1.is_array());

    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::array);
    BOOST_CHECK(v2.is(toml::value_t::array));
    BOOST_CHECK(v2.is<toml::array>());
    BOOST_CHECK(v2.is_array());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::array>().at(0).cast<toml::value_t::integer>(), 1);
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::array>().at(1).cast<toml::value_t::integer>(), 2);
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::array>().at(2).cast<toml::value_t::integer>(), 3);
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::array>().at(3).cast<toml::value_t::integer>(), 4);
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::array>().at(4).cast<toml::value_t::integer>(), 5);
    BOOST_CHECK_EQUAL(v1.as_array().at(0).as_integer(), 1);
    BOOST_CHECK_EQUAL(v1.as_array().at(1).as_integer(), 2);
    BOOST_CHECK_EQUAL(v1.as_array().at(2).as_integer(), 3);
    BOOST_CHECK_EQUAL(v1.as_array().at(3).as_integer(), 4);
    BOOST_CHECK_EQUAL(v1.as_array().at(4).as_integer(), 5);


    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::array>().at(0).cast<toml::value_t::integer>(), 6);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::array>().at(1).cast<toml::value_t::integer>(), 7);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::array>().at(2).cast<toml::value_t::integer>(), 8);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::array>().at(3).cast<toml::value_t::integer>(), 9);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::array>().at(4).cast<toml::value_t::integer>(), 0);

    v1 = {6,7,8,9,0};
    v2 = v;

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::array);
    BOOST_CHECK(v1.is(toml::value_t::array));
    BOOST_CHECK(v1.is<toml::array>());
    BOOST_CHECK(v1.is_array());

    BOOST_CHECK_EQUAL(v2.type(), toml::value_t::array);
    BOOST_CHECK(v2.is(toml::value_t::array));
    BOOST_CHECK(v2.is<toml::array>());
    BOOST_CHECK(v2.is_array());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::array>().at(0).cast<toml::value_t::integer>(), 6);
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::array>().at(1).cast<toml::value_t::integer>(), 7);
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::array>().at(2).cast<toml::value_t::integer>(), 8);
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::array>().at(3).cast<toml::value_t::integer>(), 9);
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::array>().at(4).cast<toml::value_t::integer>(), 0);
    BOOST_CHECK_EQUAL(v1.as_array().at(0).as_integer(), 6);
    BOOST_CHECK_EQUAL(v1.as_array().at(1).as_integer(), 7);
    BOOST_CHECK_EQUAL(v1.as_array().at(2).as_integer(), 8);
    BOOST_CHECK_EQUAL(v1.as_array().at(3).as_integer(), 9);
    BOOST_CHECK_EQUAL(v1.as_array().at(4).as_integer(), 0);


    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::array>().at(0).cast<toml::value_t::integer>(), 1);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::array>().at(1).cast<toml::value_t::integer>(), 2);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::array>().at(2).cast<toml::value_t::integer>(), 3);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::array>().at(3).cast<toml::value_t::integer>(), 4);
    BOOST_CHECK_EQUAL(v2.cast<toml::value_t::array>().at(4).cast<toml::value_t::integer>(), 5);
    BOOST_CHECK_EQUAL(v2.as_array().at(0).as_integer(), 1);
    BOOST_CHECK_EQUAL(v2.as_array().at(1).as_integer(), 2);
    BOOST_CHECK_EQUAL(v2.as_array().at(2).as_integer(), 3);
    BOOST_CHECK_EQUAL(v2.as_array().at(3).as_integer(), 4);
    BOOST_CHECK_EQUAL(v2.as_array().at(4).as_integer(), 5);


    toml::value v3(v1);
    BOOST_CHECK(v3 == v1);

    BOOST_CHECK_EQUAL(v3.type(), toml::value_t::array);
    BOOST_CHECK(v3.is(toml::value_t::array));
    BOOST_CHECK(v3.is<toml::array>());
    BOOST_CHECK(v3.is_array());

    BOOST_CHECK_EQUAL(v3.cast<toml::value_t::array>().at(0).cast<toml::value_t::integer>(), 6);
    BOOST_CHECK_EQUAL(v3.cast<toml::value_t::array>().at(1).cast<toml::value_t::integer>(), 7);
    BOOST_CHECK_EQUAL(v3.cast<toml::value_t::array>().at(2).cast<toml::value_t::integer>(), 8);
    BOOST_CHECK_EQUAL(v3.cast<toml::value_t::array>().at(3).cast<toml::value_t::integer>(), 9);
    BOOST_CHECK_EQUAL(v3.cast<toml::value_t::array>().at(4).cast<toml::value_t::integer>(), 0);
    BOOST_CHECK_EQUAL(v3.as_array().at(0).as_integer(), 6);
    BOOST_CHECK_EQUAL(v3.as_array().at(1).as_integer(), 7);
    BOOST_CHECK_EQUAL(v3.as_array().at(2).as_integer(), 8);
    BOOST_CHECK_EQUAL(v3.as_array().at(3).as_integer(), 9);
    BOOST_CHECK_EQUAL(v3.as_array().at(4).as_integer(), 0);


    v1 = true;
    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::boolean);
    BOOST_CHECK(v1.is(toml::value_t::boolean));
    BOOST_CHECK(v1.is<toml::boolean>());
    BOOST_CHECK(v1.is_boolean());
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::boolean>(), true);
    BOOST_CHECK_EQUAL(v1.as_boolean(), true);
}

BOOST_AUTO_TEST_CASE(test_value_table)
{
    toml::value v1{{"foo", 42}, {"bar", 3.14}, {"baz", "qux"}};

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::table);
    BOOST_CHECK(v1.is(toml::value_t::table));
    BOOST_CHECK(v1.is<toml::table>());
    BOOST_CHECK(v1.is_table());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::table>().at("foo").cast<toml::value_t::integer>(),    42);
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::table>().at("bar").cast<toml::value_t::floating>(),      3.14);
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::table>().at("baz").cast<toml::value_t::string>().str, "qux");
    BOOST_CHECK_EQUAL(v1.as_table().at("foo").as_integer(),    42);
    BOOST_CHECK_EQUAL(v1.as_table().at("bar").as_float(),   3.14);
    BOOST_CHECK_EQUAL(v1.as_table().at("baz").as_string().str, "qux");


    v1 = toml::table{{"foo", 2.71}, {"bar", 54}, {"baz", "quux"}};

    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::table);
    BOOST_CHECK(v1.is(toml::value_t::table));
    BOOST_CHECK(v1.is<toml::table>());
    BOOST_CHECK(v1.is_table());

    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::table>().at("foo").cast<toml::value_t::floating>(),      2.71);
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::table>().at("bar").cast<toml::value_t::integer>(),    54);
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::table>().at("baz").cast<toml::value_t::string>().str, "quux");
    BOOST_CHECK_EQUAL(v1.as_table().at("foo").as_float(),   2.71);
    BOOST_CHECK_EQUAL(v1.as_table().at("bar").as_integer(),    54);
    BOOST_CHECK_EQUAL(v1.as_table().at("baz").as_string().str, "quux");


    toml::value v3(v1);
    BOOST_CHECK(v3 == v1);

    BOOST_CHECK_EQUAL(v3.type(), toml::value_t::table);
    BOOST_CHECK(v3.is(toml::value_t::table));
    BOOST_CHECK(v3.is<toml::table>());
    BOOST_CHECK(v3.is_table());

    BOOST_CHECK_EQUAL(v3.cast<toml::value_t::table>().at("foo").cast<toml::value_t::floating>(),      2.71);
    BOOST_CHECK_EQUAL(v3.cast<toml::value_t::table>().at("bar").cast<toml::value_t::integer>(),    54);
    BOOST_CHECK_EQUAL(v3.cast<toml::value_t::table>().at("baz").cast<toml::value_t::string>().str, "quux");
    BOOST_CHECK_EQUAL(v3.as_table().at("foo").as_float(),   2.71);
    BOOST_CHECK_EQUAL(v3.as_table().at("bar").as_integer(),    54);
    BOOST_CHECK_EQUAL(v3.as_table().at("baz").as_string().str, "quux");


    v1 = true;
    BOOST_CHECK_EQUAL(v1.type(), toml::value_t::boolean);
    BOOST_CHECK(v1.is(toml::value_t::boolean));
    BOOST_CHECK(v1.is<toml::boolean>());
    BOOST_CHECK(v1.is_boolean());
    BOOST_CHECK_EQUAL(v1.cast<toml::value_t::boolean>(), true);
    BOOST_CHECK_EQUAL(v1.as_boolean(), true);
}

BOOST_AUTO_TEST_CASE(test_value_empty)
{
    toml::value v1;
    BOOST_CHECK(v1.is_uninitialized());
    BOOST_CHECK(v1.is(toml::value_t::empty));
}

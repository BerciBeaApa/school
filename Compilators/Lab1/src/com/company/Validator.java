package com.company;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Paul on 28.10.2015.
 */
public class Validator {
    protected boolean validatePattern(String s, String pattern) {
        return s.matches(pattern);
    }
}

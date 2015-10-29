package com.company;

import sun.misc.IOUtils;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by Paul on 28.10.2015.
 */
public class FileManager {
    private String fileName;

    public FileManager(String fileName) {
        this.fileName = fileName;
    }

    public List<String> splitToWords(String rawData) {
        List<String> words = new ArrayList<String>();
        for (String s : rawData.split("\\s")) {
            words.add(s);
        }
        return  words;
    }

    public String readFromFile()
    {
        String content = null;
        File file = new File(fileName);
        FileReader reader = null;
        try {
            reader = new FileReader(file);
            char[] chars = new char[(int) file.length()];
            reader.read(chars);
            content = new String(chars);
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if(reader !=null){
                try {
                    reader.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        return content;
    }
}

package com.example.ncs.knockknock;

/**
 * Created by nsc1303-PJH on 2016-12-09.
 */

public class FineDust {

    private String id;
    private String text;
    private String name;
    private String photoUrl;

    public FineDust() {
    }

    public FineDust(String text, String name, String photoUrl) {
        this.text = text;
        this.name = name;
        this.photoUrl = photoUrl;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setText(String text) {
        this.text = text;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPhotoUrl() {
        return photoUrl;
    }

    public String getText() {
        return text;
    }

    public void setPhotoUrl(String photoUrl) {
        this.photoUrl = photoUrl;
    }
}

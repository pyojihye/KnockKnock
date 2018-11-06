package com.example.ncs.knockknock;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.PowerManager;
import android.util.Log;
import android.view.Window;
import android.view.WindowManager;

public class IntroActivity extends Activity {

    private final String TAG="IntroActivity";
    Handler h;

    public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_TURN_SCREEN_ON | WindowManager.LayoutParams.FLAG_SHOW_WHEN_LOCKED | WindowManager.LayoutParams.FLAG_DISMISS_KEYGUARD);

        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.activity_intro);
        h=new Handler();
        h.postDelayed(irun,2000);

        Log.d(TAG,"onCreate()");
    }

    Runnable irun=new Runnable(){
        public void run(){
            Intent i=new Intent(IntroActivity.this,SignInActivity.class);
            startActivity(i);
            finish();
            overridePendingTransition(android.R.anim.fade_in,android.R.anim.fade_out);
            Log.d(TAG,"Runnable()");
        }
    };

    @Override
    public void onBackPressed(){
        super.onBackPressed();
        h.removeCallbacks(irun);
        Log.d(TAG,"onBackPressed()");
    }

    public static boolean isScreenOn(Context context) {
        return ((PowerManager)context.getSystemService(Context.POWER_SERVICE)).isScreenOn();
    }

}

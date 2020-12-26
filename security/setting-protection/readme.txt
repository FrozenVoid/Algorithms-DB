the idea of setting protection is to create a specific regime of settings
in the application that would be followed unless explicitly overriden.
Example;
1.App has Default-On setting for parameter X, which is setting-protected.
Any attempt to change from Default-On will require password input or manual confirmation.
2.App has Default-Off setting for parameter X, which is setting-protected.
Any attempt to change from Default-Off will require password input or manual confirmation.
3.Removing Default-on/off protection requires manual validation(or just limited
to switch from Default-on/default-off)


benefits;
1.Protects vital settings from dumb users, misclicks, exploits,etc.
2.Stabilizes settings to avoid users getting unpleasant effects.
3.Prevents unauthorized changes by scripts/automation programs/hotkeys/etc.


